#pragma once
#include <iostream>
#include <mutex>

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
