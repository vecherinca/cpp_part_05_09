#include "../headers/Base.hpp"
#include "../headers/A.hpp"
#include "../headers/B.hpp"
#include "../headers/C.hpp"

#include <cstdlib> 
#include <iostream>
	
Base * generate(void)
{
	int randNum = (rand() % 3) + 1;
	switch (randNum)
	{
		case 1:
			return(new A);
		case 2:
			return(new B);
		case 3:
			return(new C);
	}
	return (NULL);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class pointed by p is A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class pointed by p is B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class pointed by p is C" << std::endl;
}
void identify(Base& p)
{
	try{A temp = dynamic_cast<A &>(p);
		std::cout << "Reference type is A" << std::endl;}
	catch(const std::exception &e){}
	try{B temp = dynamic_cast<B &>(p);
		std::cout << "Reference type is B" << std::endl;}
	catch(const std::exception &e){}
	try{C temp = dynamic_cast<C &>(p);
		std::cout << "Reference type is C" << std::endl;}
	catch(const std::exception &e){}
}
int main()
{
	srand(time(NULL));
	
	Base *Class;
	Class = generate();
	
	identify(Class);
	identify(*Class);

	Base *Class2;
	Class2 = generate();
	
	identify(Class2);
	identify(*Class2);

	Base *Class3;
	Class3 = generate();
	
	identify(Class3);
	identify(*Class3);

	delete Class;
	delete Class2;
	delete Class3;
}