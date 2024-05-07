#ifndef BASE_H
# define BASE_H
#include <iostream>

class Base {

	public:
		virtual ~Base( void )
		{
			std::cout << "[Base] class destructed" << std::endl;
		};
};

#endif