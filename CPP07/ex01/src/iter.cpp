
#include "../headers/iter.hpp"

Iter::Iter( void ){

	return ;
}

Iter::Iter(const Iter &sc){

	(void) sc;
	return ;
}

Iter::~Iter( void ){

	return ;
}

Iter &Iter::operator=(const Iter &sc){

		(void) sc;

	return (*this);
}

