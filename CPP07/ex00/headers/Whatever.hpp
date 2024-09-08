#ifndef WHATEVER_HPP
#define WHATEVER_HPP
#include <iostream>
#include <cerrno>
#include <climits>
#include <cstdio>
#include <cfloat>
#include <cmath>
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string CYAN = "\033[36m";
const std::string RESET = "\033[0m";


class Whatever
{
	public:
		Whatever();
		~Whatever();
		Whatever(const Whatever &cls);
		Whatever &operator=(const Whatever &cls);
		template<typename T>
		static void swap(T &a, T &b) {
    	T c = a;
    	a = b;
    	b = c;
    	return ;
		}
		template<typename T>
			static T min(T &a, T &b) {
			if (a > b)
				return b;
			else
				return a;
		}
		template<typename T>
			static T max(T &a, T &b) {
			if (a > b)
				return a;
			else
				return b;
		}
			
};
#endif