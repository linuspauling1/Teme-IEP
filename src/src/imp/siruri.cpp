#include "siruri.hpp"

Siruri::Siruri(char* sir)
	: lungime(strlen(sir)) 
{
	std::cout << "Eu sunt constructorul.\n";
	inceput = new char[lungime + 1];
	strcpy(inceput,sir);
}

Siruri::Siruri()
	: lungime(strlen("mere"))
{
	std::cout << "Eu sunt constructorul default.\n";
	inceput = new char[lungime + 1];
	strcpy(inceput,"mere");
}

Siruri::Siruri(const Siruri& siruri)
{
	std::cout << "Eu sunt cpoy-constructor-ul.\n";
	this->lungime = siruri.lungime;
	this->inceput = new char[lungime + 1];
	strcpy(this->inceput,siruri.inceput);
}

Siruri::Siruri(Siruri&& siruri)
{
	std::cout << "Eu sunt move-constructor-ul.\n";
	this->lungime = siruri.lungime;
	this->inceput = siruri.inceput;
	siruri.lungime = 0;
	siruri.inceput = nullptr;
}

Siruri::~Siruri()
{
	std::cout << "Eu sunt destructorul.\n";
	lungime = 0;
	delete[] inceput;
}

Siruri& Siruri::operator=(const Siruri& siruri)
{
	std::cout << "Eu sunt operatorul de copiere.\n";
	this->lungime = siruri.lungime;
	this->inceput = new char[lungime + 1];
	strcpy(this->inceput,siruri.inceput);
	return *this;
}

Siruri& Siruri::operator=(Siruri&& siruri)
{
	std::cout << "Eu sunt operatorul de mutare.\n";
	this->lungime = siruri.lungime;
	this->inceput = siruri.inceput;
	siruri.lungime = 0;
	siruri.inceput = nullptr;
	return *this;
}

void Siruri::afisare()
{
	printf("%s\n",inceput);
}

void functie()
{
	
	bool flag;
	char sir[255];
	while(true)
	{
		std::cout << "introduceti un sir de caractere: ";
		scanf("%s",sir);
		std::unique_ptr<Siruri> indicator = std::make_unique<Siruri>(sir);
		std::cout << "introduceti un flag: ";
		std::cin >> flag;
		indicator->afisare();
		if(flag)
			break;
	}
}

void procedura()
{
	std::weak_ptr<Siruri> wk;
	{
		std::shared_ptr<Siruri> sp0;
		{
			std::shared_ptr<Siruri> sp1;
			{
				std::shared_ptr<Siruri> sp2;
				{
					std::shared_ptr<Siruri> sp = std::make_shared<Siruri>();//pui aici argumentul
					sp0 = sp;
					sp1 = sp;
					sp2 = sp;
					wk = sp;
					sp->afisare();
					wk.lock()->afisare();
				}
				sp2->afisare();
				wk.lock()->afisare();
			}
			sp1->afisare();
			wk.lock()->afisare();
		}
		sp0->afisare();
		wk.lock()->afisare();
	}
	if(auto tmp = wk.lock())
		tmp->afisare();
	else
		std::cout << "Acest pointer nu mai exista.\n";
}
