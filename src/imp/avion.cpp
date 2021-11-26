#include "avion.hpp"
#include <iostream>

void Avion::m_copy(const Avion& avion)
{
	setSize_nume(avion.size_nume);
	setNume(avion.nume);
	setMotoare(avion.motoare);
	setConsum(avion.consum);
	setPasageri(avion.pasageri);
}

void Avion::m_move(Avion&& avion)
{
	size_nume = avion.size_nume;
	nume = avion.nume;
	motoare = avion.motoare;
	consum = avion.consum;
	pasageri = avion.pasageri;
	avion.nume = nullptr;//elibaram locul de memorie
	avion.size_nume = 0;//resetam valorile din
	avion.motoare = 0;//memoria staitca
	avion.consum = 0;
	avion.pasageri = 0;
}

Avion::Avion()
	: size_nume(5),nume((char*)"B747"),motoare(4),consum(1470.5f),pasageri(500)
{
	std::cout << "constructor default" << std::endl;
	setNume(nume);//evitam posibile erori
	setFunctional(false);//marcam apelul de ctor default
}

Avion::Avion(int size_nume,char* nume,int motoare, float consum,int pasageri)
	: size_nume(size_nume),nume(nume),motoare(motoare),consum(consum),pasageri(pasageri)
{
	std::cout << "constructor" << std::endl;
	setNume(nume);//evitam posibile erori
	setFunctional(true);//marcam apelul de ctor construit de noi
}

Avion::Avion(const Avion& avion)
	: Aeronava(avion)//copie totala
{
	std::cout << "copy constructor" << std::endl;
	m_copy(avion);
}

Avion::Avion(Avion&& avion)
{
	std::cout << "move constructor" << std::endl;
	m_move((Avion&&)avion);
}

Avion::~Avion()
{
	std::cout << "destructor" << std::endl;
	delete[] nume;//elibaram locul de memorie
	size_nume = 0;//resetam valorile din
	motoare = 0;//memoria staitca
	consum = 0;
	pasageri = 0;
}

Avion& Avion::operator=(const Avion& avion)
{
	std::cout << "copy operator" << std::endl;
	Aeronava::operator=(avion);//copie totala
	m_copy(avion);
	return *this;
}

Avion& Avion::operator=(Avion&& avion)
{
	std::cout << "move operator" << std::endl;
	if(&avion != this)
	{
		delete[] nume;
		m_move((Avion&&)avion);
	}
	return *this;
}

void Avion::afiseaza()
{
	std::cout << "Avion" << std::endl;
	std::cout << "functional: " << functional << std::endl;
	std::cout << "size_nume: " << getSize_nume() << std::endl;
	std::cout << "nume: " << getNume() << std::endl;
	std::cout << "motoare: " << getMotoare() << std::endl;
	std::cout << "consum: " << getConsum() << std::endl;
	std::cout << "pasageri: " << getPasageri() << std::endl;
	std::cout << std::endl;
}

void Avion::setNume(char* nume)
{
	this->nume = new char[size_nume];
	int i;
	for(i = 0;i < size_nume;++i)
		this->nume[i] = nume[i]; 
}

void Avion::setSize_nume(int size_nume)
{
	this->size_nume = size_nume;
}

void Avion::setMotoare(int motoare)
{
	this->motoare = motoare;
}

void Avion::setConsum(float consum)
{
	this->consum = consum;
}

void Avion::setPasageri(int pasageri)
{
	this->pasageri = pasageri;
}

char* Avion::getNume()
{
	char* nume = new char[size_nume];
	int i;
	for(i = 0;i < size_nume;++i)
		nume[i] = this->nume[i];
	return nume;//intoarcem o copie a numelui
}

int Avion::getSize_nume()
{
	return size_nume;
}

int Avion::getMotoare()
{
	return motoare;
}

float Avion::getConsum()
{
	return consum;
}

int Avion::getPasageri()
{
	return pasageri;
}
