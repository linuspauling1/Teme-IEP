#pragma once

class Aeronava{
	protected:
		bool functional;
	public:
		Aeronava();
		Aeronava(const Aeronava&);
		Aeronava(Aeronava&&);
		~Aeronava();
		Aeronava& operator=(const Aeronava&);
		Aeronava& operator=(Aeronava&&);
		void setFunctional(bool);
		virtual void afiseaza();
};
