#include "masina.hpp"
#include "avion.hpp"
#include "racheta.hpp"
#include "hovercraft.hpp"
#include "lacat.hpp"
#include <utility>
#include <thread>
#include <cstdio>
#include <cstring>
#include <chrono>

void citire(bool&, char*, Lacat&);
void afisare(bool&, char*, Lacat&);

int main(){
	/*
	Avion a;//constructor default
	a.afiseaza();
	Avion b(5,(char*)"B777",2,10000.08,300);//constructor
	b.afiseaza();
	Avion c = a;//copy constructor
	c.afiseaza();
	c.setMotoare(4);
	c.afiseaza();
	a.afiseaza();
	c = b;//copy assignment operator
	c.afiseaza();
	c.setMotoare(3);
	c.afiseaza();
	b.afiseaza();
	Avion d = Avion();//move constructor
	d.afiseaza();
	c = std::move(a);//move assignment operator
	a.afiseaza();//variabila a fost distrusa in constructorul lui c
	c.afiseaza();//ar trebui sa fie identic cu continutul lui a
	*/
	/*--------------------------------------------------------------*/
	/*
	Racheta w;//constructor default
	w.afiseaza();
	Racheta x(5,(char*)"ALLL",3,14003.45,14);//constructor
	x.afiseaza();
	Racheta y = w;//copy constructor
	y.afiseaza();
	y = x;//copy assignemnt operator
	y.afiseaza();
	Racheta z;
	z = Racheta();//move constructor
	z.afiseaza();
	y = std::move(w);//move assignment operator
	y.afiseaza();
	*/
	//mutex:
	bool steag = true;
	char string[] = "mere";
	Lacat lacat;
	std::thread fir_citire(citire,std::ref(steag),string, std::ref(lacat));
	std::thread fir_afisare(afisare,std::ref(steag),string, std::ref(lacat));
	fir_citire.join();
	fir_afisare.join();
	return 0;
}

void citire(bool& flag,char* sir, Lacat& lacat)
{
	flag = true;//pentru siguranta
	while(true)
	{
		scanf("%s",sir);
		lacat.lock();
		if(!strcmp(sir,"stop"))//operatia nu e atomica
			break;
		lacat.unlock();//apare o problema pentru ca programul nu ajunge aici tot timpul!
	}
	//lacat.unlock();//si atunci trebuie sa descuiem aici lacatul
	flag = false;
	return;
}

void afisare(bool& flag, char* sir, Lacat& lacat)
{
	using namespace std::literals::chrono_literals;//evitam sa scriem mult cod repetitiv
	auto start = std::chrono::high_resolution_clock::now();//de acum incepem cronometrarea
	while(flag)
	{
		lacat.lock();
		auto end = std::chrono::high_resolution_clock::now();//pana aici verificam timpul scrus
		std::chrono::duration<float> duration = end - start;
		if(duration.count() > 0.5)
		{
			start = end;
			std::cout << "Funtionez " << sir <<"!\n";//nu e atomica operatia	
		}
		lacat.unlock();
	}
	return;
}
