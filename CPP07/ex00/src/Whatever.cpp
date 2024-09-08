
#include "../headers/Whatever.hpp"
Whatever::Whatever( void ){

	return ;
}

Whatever::Whatever(const Whatever &sc){

	(void) sc;
	return ;
}

Whatever::~Whatever( void ){

	return ;
}

Whatever &Whatever::operator=(const Whatever &sc){

	(void) sc;

	return (*this);
}

