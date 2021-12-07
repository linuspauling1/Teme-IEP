#include "racheta.hpp"
#include <iostream>

void Racheta::m_copy(const Racheta& racheta)
{
	setSize_serie(racheta.size_serie);
	setSerie(racheta.serie);
	setComponente(racheta.componente);
	setCarburant(racheta.carburant);
	setAstronauti(racheta.astronauti);
}

void Racheta::m_move(Racheta&& racheta)
{
	size_serie = racheta.size_serie;
	serie = racheta.serie;
	componente = racheta.componente;
	carburant = racheta.carburant;
	astronauti = racheta.astronauti;
	racheta.serie = nullptr;
	racheta.size_serie = 0;
	racheta.componente = 0;
	racheta.carburant = 0;
	racheta.astronauti = 0;
}

Racheta::Racheta()
	:size_serie(10),serie((char*)"MIR1024"),componente(9),carburant(1000000.0),astronauti(15)
{
	std::cout << "constructor default" << std::endl;
	setSerie(serie);//evitam erorile
	setFunctional(true);//la intializare cu constructorul default setam pe "true" caracteristica avionului de a fi functional
}

Racheta::Racheta(int size_serie,char* serie,short componente,long double carburant, int astronauti)
	:size_serie(size_serie),serie(serie),componente(componente),carburant(carburant),astronauti(astronauti)
{
	std::cout << "constructor" << std::endl;
	setSerie(serie);//evitam erorile
	setFunctional(false);//la initializarea cu constructorul creat de noi setam pe "false" caracteristica avionului de a fi functional
}

Racheta::Racheta(const Racheta& racheta)
	:Aeronava(racheta)//copie totala
{
	std::cout << "copy constructor" << std::endl;
	m_copy(racheta);
}

Racheta::Racheta(Racheta&& racheta)
{
	std::cout << "move constructor" << std::endl;
	m_move((Racheta&&)racheta);
}

Racheta::~Racheta()
{
	std::cout << "destructor" << std::endl;
	delete[] serie;
	size_serie = 0;
	serie = 0;
	componente = 0;
	carburant = 0;
	astronauti = 0;

}

Racheta& Racheta::operator=(const Racheta& racheta)
{
	std::cout << "copy assignment operator" << std::endl;
	Aeronava::operator=(racheta);//copie totala
	m_copy(racheta);
	return *this;
}

Racheta& Racheta::operator=(Racheta&& racheta)
{
	if(&racheta != this)
	{
		delete[] serie; 
		std::cout << "move assignment operator" << std::endl;
		m_move((Racheta&&)racheta);
	}
	return *this;
}

void Racheta::afiseaza()
{
	std::cout << "Racheta" << std::endl;
	std::cout << "functional: " << functional << std::endl;
	std::cout << "size_serie: " << size_serie << std::endl;
	std::cout << "serie: " << serie << std::endl;
	std::cout << "componente: " << componente << std::endl;
	std::cout << "carburant: " << carburant << std::endl;
	std::cout << "astronauti: " << astronauti << std::endl;
	std::cout << std::endl;
}

void Racheta::setSize_serie(int size_serie)
{
	this->size_serie = size_serie;
}

void Racheta::setSerie(char* serie)
{
	this->serie = new char[size_serie];
	int i;
	for(i = 0;i < size_serie;++i)
		this->serie[i] = serie[i];
}

void Racheta::setComponente(short componente)
{
	this->componente = componente;
}

void Racheta::setCarburant(long double carburant)
{
	this->carburant = carburant;
}

void Racheta::setAstronauti(int astronauti)
{
	this->astronauti = astronauti;
}

int Racheta::getSize_serie()
{
	return size_serie;
}

char* Racheta::getSerie()
{
	serie = new char[size_serie];
	int i;
	for(i = 0;i < size_serie;++i)
		serie[i] = this->serie[i];
	return serie;
}

short Racheta::getComponente()
{
	return componente;
}

long double Racheta::getCarburant()
{
	return carburant;
}

int Racheta::getAstronauti()
{
	return astronauti;
}