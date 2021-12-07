#pragma once
#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <cstdio>
#include <cstring>

class Lacat
{
	public:
		explicit Lacat();
		Lacat(const Lacat&) = delete;
		~Lacat();
		void lock();
		void unlock();
	private:
		std::mutex* mx;
		bool inchis;
		//Lacat& operator=(const Lacat&);
};

void citire(bool&, char*, Lacat&);
void afisare(bool&, char*, Lacat&);
