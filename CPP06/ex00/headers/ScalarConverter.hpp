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

enum s_Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NONE
};

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &cls);
		ScalarConverter &operator=(const ScalarConverter &cls);
	public:
		static void convert(std::string &input);	
		class NonExistentType: public std::exception
		{
			public:
                virtual const char *what() const throw();
		};
		class ConversionImpossible: public std::exception
		{
			public:
                virtual const char *what() const throw();
		};
		class OutputNotToDisplay: public std::exception
		{
			public:
                virtual const char *what() const throw();
		};

};