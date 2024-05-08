
#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <cerrno>
#include <climits>
#include <cstdio>
#include <cfloat>
#include <cmath>
#include <stdexcept>

const std::string RESET = "\033[0m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int len_array;
	public:
    	
		Array()
		{
			std::cout << "Simple Constructor Called" << std::endl;
			this -> array = new T();
			this -> len_array = 0;
		}
		Array(unsigned int size)
		{
			std::cout << "Constructor Called" << std::endl;
			this -> len_array = size;
			this -> array = new T[this -> len_array];
		}
		Array(const Array &cls)
		{
			std::cout << "Copy Constructor Called" << std::endl;
			this -> len_array = cls.len_array;
			this -> array = new T[this -> len_array];
			for (unsigned int i = 0; i < this -> len_array; i++)
					this -> array[i] = cls.array[i];
			
		}
		Array &operator=(const Array &cls) {
		std::cout << "Assignment Operator Called" << std::endl;
		if (this != &cls) {
			delete [] this->array;
			this->len_array = cls.len_array;
			this->array = new T[this->len_array];
			for (unsigned int i = 0; i < this->len_array; i++) {
				this->array[i] = cls.array[i];
			}
    	}
    return *this;
}
		T &operator[](unsigned int i)
		{
			if (i >= this -> len_array)
				throw std::out_of_range("Index out of range");
			return(this -> array[i]);

		}
		~Array() {
			std::cout << "Destructor Called" << std::endl;
			delete [] this-> array;
		}
		void size()
		{	
			return (this -> len_array);
		}
  

};

#endif