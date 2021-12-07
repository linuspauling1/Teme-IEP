#include <iostream>
#include <memory>


//contraexemplu:

struct B;//avem ndevoie de B declarat

struct A
{
		std::shared_ptr<B> spA;
		~A();
};

struct B
{
		std::shared_ptr<A> spB;
		~B();
};


//exemplu:

struct D;//avem ndevoie de D declarat

struct C
{
		std::weak_ptr<D> wpC;
		~C();
};

struct D
{
		std::weak_ptr<C> wpD;
		~D();
};

void testam();
