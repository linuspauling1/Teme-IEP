#pragma once
#include "aeronava.hpp"

class Racheta:public Aeronava {
	private:
		int size_serie;//dimensiunea seriei rachetei
		char* serie;//seria rachetei
		short componente;
		long double carburant;
		int astronauti;
		void m_copy(const Racheta&);
		void m_move(Racheta&&);
	public:
		Racheta();//default constructor
		Racheta(int,char*,short,long double,int);
		Racheta(const Racheta&);//copy constructor
		Racheta(Racheta&&);//move constructor
		~Racheta();//destructor
		Racheta& operator=(const Racheta&);//copy assignment operator
		Racheta& operator=(Racheta&&);//move assignment operator
		void afiseaza() override;
		//getter-e si setter-e
		//setter-e:
		void setSize_serie(int);
		void setSerie(char*);
		void setComponente(short);
		void setCarburant(long double);
		void setAstronauti(int);
		//getter-e:
		int getSize_serie();
		char* getSerie();
		short getComponente();
		long double getCarburant();
		int getAstronauti();
};