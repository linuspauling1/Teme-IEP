#include "lacat.hpp"

Lacat::Lacat()
{
	mx = new std::mutex;
	mx->unlock();
	inchis = false;
}

Lacat::~Lacat()
{
	if(inchis)
	{
		mx->unlock();
		inchis = false;
	}
}

void Lacat::lock()
{
	if(!inchis)
	{
		mx->lock();
		inchis = true;
	}
}

void Lacat::unlock()
{
	if(inchis)
	{
		mx->unlock();
		inchis = false;
	}
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
