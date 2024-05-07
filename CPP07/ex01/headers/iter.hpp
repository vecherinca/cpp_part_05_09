#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>
#include <cerrno>
#include <climits>
#include <cstdio>
#include <cfloat>
#include <cmath>
const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";



class Iter
{
	public:
		Iter();
		~Iter();
		Iter(const Iter &cls);
		Iter &operator=(const Iter &cls);
		template<typename T>
		static void iter(T *address, size_t length, void (*f)(T)) {

				for (size_t i = 0; i < length; i++)
					f(address[i]);
    	
    	return ;
		}
			
};
#endif