#pragma once

class Avion{
	private:
		int size_nume;//dimensiunea numelui
		char* nume;//numele avionului
		int motoare;
		float consum;
		int pasageri;
	public:
		Avion();//default constructor
		Avion(int size_nume,char* nume,int motoare, float consum,int pasageri);//constructor
		Avion(const Avion&);//copy constrcutor
		Avion(Avion&&);//move constructor
		~Avion();//destructor
		Avion& operator=(const Avion&);//copy assignment operator
		Avion& operator=(Avion&&);//move assignment operator
		void afiseaza();
		//getter-e si setter-e
		//setter-e:
		void setSize_nume(int size_nume);
		void setNume(char* nume);
		void setMotoare(int motoare);
		void setConsum(float consum);
		void setPasageri(int pasageri);
		//getter-e:
		int getSize_nume();
		char* getNume();
		int getMotoare();
		float getConsum();
		int getPasageri();
}