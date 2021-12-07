#include "masina.hpp"
#include "avion.hpp"
#include "racheta.hpp"
#include "hovercraft.hpp"
#include "lacat.hpp"
#include "siruri.hpp"
#include <utility>

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
	//RAII pointers:
	functie();
	std::cout << std::endl;
	procedura();
	return 0;
}
