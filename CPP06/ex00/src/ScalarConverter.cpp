
#include "../headers/ScalarConverter.hpp"

bool isInt(std::string &input)
{
	int i = 0;
	int len = input.length();
	if (input[i] == '+' || input[i] == '-')
		i++;
	if (i == len)
		return (false);
	while (i < len)
	{
		if (!isdigit(input[i]))
			return (false);
		i++;
	}
	if (atoll(input.c_str()) > INT_MAX || atoll(input.c_str()) < INT_MIN)
		return(false);

	return(true);

}

bool isFloat(std::string &input)
{
	int i = 0;
	int len = input.length();
	if (input == "inff" || input == "-inff" || input == "nanf")
		return(true);
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < len && isdigit(input[i]))
		i++;
	if (input[i] != '.')
		return(false);
	i++;
	while (i < len && isdigit(input[i]))
		i++;
	if (input[i] != 'f')
		return(false);
	i++;
	if (i != len)
		return(false);
	if (atof(input.c_str()) > FLT_MAX || atof (input.c_str()) < -FLT_MAX)
		return(false);
	return(true);
}

bool isDouble(std::string &input)
{
	int i = 0;
	int len = input.length();
	if (input == "-inf" || input == "+inf" || input == "nan")
		return(true);
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < len && isdigit(input[i]))
		i++;
	if (input[i] != '.')
		return(false);
	i++;
	if (i == len)
		return (false);
	while (i < len && isdigit(input[i]))
		i++;
	if (i != len)
		return (false);
	if (atof(input.c_str()) > LDBL_MAX || atof (input.c_str()) < -LDBL_MAX)
		return(false);

	return(true);

}

bool isChar(std::string &input)
{
	int i = 0;
	int len = input.length();
	if (isprint(input[i]) && len == 1)
		return(true);
	return(false);
}

int defineType(std::string &input)
{
	if (isInt(input))
		return(INT);
	else if (isFloat(input))
		return(FLOAT);
	else if (isDouble(input))
		return(DOUBLE);
	else if (isChar(input))
		return(CHAR);
	else 
		return(123);	
}

void ScalarConverter::convert(std::string &input)
{
	int out = defineType(input);
	std::cout << "DEFINED TYPE IS: " << out << std::endl;
}