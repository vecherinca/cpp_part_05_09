#include "../headers/Serializer.hpp"


Serializer::Serializer( void ){
	
	return ;
}

Serializer::Serializer(const Serializer &s){

	(void)s;
	return ;
}

Serializer::~Serializer( void ){


	return ;
}

Serializer &Serializer::operator=(const Serializer &s){

	(void)s;

	return (*this);
}