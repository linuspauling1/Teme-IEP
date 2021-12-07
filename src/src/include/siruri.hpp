#include <iostream>
#include <cstring>
#include <memory>

class Siruri
{
	public:
		Siruri(char*);
		Siruri();
		Siruri(const Siruri&);
		Siruri(Siruri&&);
		~Siruri();
		Siruri& operator=(const Siruri&);
		Siruri& operator=(Siruri&&);
		void afisare();
	private:
		int lungime;
		char* inceput;

};

void functie();
void procedura();
