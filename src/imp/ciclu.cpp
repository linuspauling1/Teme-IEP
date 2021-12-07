#include "ciclu.hpp"

A::~A()
{
	std::cout << "Sunt A si am murit.\n";
}

B::~B()
{
	std::cout << "Sunt B si am murit.\n";
}

C::~C()
{
	std::cout << "Sunt C si am murit.\n";
}

D::~D()
{
	std::cout << "Sunt D si am murit.\n";
}

void testam()
{
	std::shared_ptr<A> a = std::make_shared<A>();
	std::shared_ptr<B> b = std::make_shared<B>();
	std::shared_ptr<C> c = std::make_shared<C>();
	std::shared_ptr<D> d = std::make_shared<D>();
	a->spA = b;
	b->spB = a;
	c->wpC.lock() = d;
	d->wpD.lock() = c;
}
