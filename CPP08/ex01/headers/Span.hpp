#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <algorithm>
#include <iostream>
#include <iterator> 	 	 
#include <stdexcept>
#include <vector>
#include <list>
	
class Span
{
	private: 
		unsigned int len_array;
	public:
		Span();
		Span(unsigned int len_array);
		Span(const Span &cls);
		Span &operator=(const Span &cls);
		~Span();
		void addNumber(int number);
		unsigned int shortestSpan( void );
		unsigned int longestSpan( void );
		// Add add_range
};
#endif