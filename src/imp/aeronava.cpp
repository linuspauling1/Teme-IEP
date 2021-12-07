#include "aeronava.hpp"
#include <iostream>

Aeronava::Aeronava() : functional(false) {}

Aeronava::Aeronava(const Aeronava& aeronava) : functional(aeronava.functional) {}

Aeronava::Aeronava(Aeronava&& aeronava) : functional(aeronava.functional) {}

Aeronava::~Aeronava() {}

Aeronava& Aeronava::operator=(const Aeronava& aeronava)
{
	functional = aeronava.functional;
	return *this;
}

Aeronava& Aeronava::operator=(Aeronava&& aeronava)
{
	functional = aeronava.functional;
	return *this;
}

void Aeronava::setFunctional(bool functional)
{
	this->functional = functional;
}

void Aeronava::afiseaza()
{
	std::cout << "ceva nu e bine\n";
}
