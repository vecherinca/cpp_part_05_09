#include "../headers/Base.hpp"
#include "../headers/A.hpp"
#include "../headers/B.hpp"
#include "../headers/C.hpp"

#include <cstdlib> 
#include <iostream>

Base * generate(void)
{
	srand(time(NULL));

	int randNum = (rand() % 3) + 1;
	std::cout << "out: " << randNum;
	return(NULL);
}

int main()
{
	generate();
}