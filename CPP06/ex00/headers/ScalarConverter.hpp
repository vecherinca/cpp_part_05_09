#include <iostream>
#include <cerrno>
#include <climits>
#include <cstdio>
#include <cfloat>

#include <cmath>

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
};