#include "lacat.hpp"

Lacat::Lacat()
{
	mx = new std::mutex;
	mx->unlock();
	inchis = false;
}

Lacat::~Lacat()
{
	if(inchis)
	{
		mx->unlock();
		inchis = false;
	}
}

void Lacat::lock()
{
	if(!inchis)
	{
		mx->lock();
		inchis = true;
	}
}

void Lacat::unlock()
{
	if(inchis)
	{
		mx->unlock();
		inchis = false;
	}
}
