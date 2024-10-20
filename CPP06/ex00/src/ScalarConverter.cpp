
#include "../headers/ScalarConverter.hpp"
ScalarConverter::ScalarConverter( void ){

	return ;
}

ScalarConverter::~ScalarConverter( void ){

	return ;
}


ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src) {
	if (this != &src) {}
	return (*this);
}

bool	isInt(std::string &input)
{
	int	i;
	int	len;

	i = 0;
	len = input.length();
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
		return (false);
	return (true);
}

bool	isFloat(std::string &input)
{
	int	i;
	int	len;

	i = 0;
	len = input.length();
	if (input == "inff" || input == "-inff" || input == "nanf")
		return (true);
	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < len && isdigit(input[i]))
		i++;
	if (input[i] != '.')
		return (false);
	i++;
	while (i < len && isdigit(input[i]))
		i++;
	if (input[i] != 'f')
		return (false);
	i++;
	if (i != len)
		return (false);
	if (atof(input.c_str()) > FLT_MAX || atof(input.c_str()) < -FLT_MAX)
		return (false);
	return (true);
}

bool	isDouble(std::string &input)
{
	int	i;
	int	len;

	i = 0;
	len = input.length();

	if (input == "-inf" || input == "+inf" || input == "nan" || input == "inf" )
		return (true);

	if (input[i] == '+' || input[i] == '-')
		i++;
	while (i < len && isdigit(input[i]))
		i++;
	if (input[i] != '.')
		return (false);
	i++;
	if (i == len)
		return (false);
	while (i < len && isdigit(input[i]))
		i++;
	if (i != len)
		return (false);
	if (atof(input.c_str()) > LDBL_MAX || atof(input.c_str()) < -LDBL_MAX)
		return (false);
	return (true);
}

bool	isChar(std::string &input)
{
	int	i;
	int	len;

	i = 0;
	len = input.length();
	if (isprint(input[i]) && len == 1)
		return (true);
	return (false);
}

int	defineType(std::string &input)
{
	if (isInt(input))
		return (INT);
	else if (isFloat(input))
		return (FLOAT);
	else if (isDouble(input))
		return (DOUBLE);
	else if (isChar(input))
		return (CHAR);
	else
		throw ScalarConverter::NonExistentType();
}

int	toInt(std::string &input)
{
	double	value;

	
	if (input == "inf" || input == "-inf" || input == "inff"
		|| input == "-inff" || input =="nan" || input == "nanf")
		throw ScalarConverter::ConversionImpossible();
	if (defineType(input) == CHAR)
		return (static_cast<int>(input[0]));
	value = atof(input.c_str());
	if (value > INT_MAX || value < INT_MIN)
		throw ScalarConverter::OutputNotToDisplay();
	return (static_cast<int>(value));
}

double	toDouble(std::string &input)
{
	long double	value;

	if (input == "-inff" || input == "-inf")
		return (-DBL_MAX * 2);
	if (input == "+inff" || input == "+inf" || input == "inff" || input == "inf")
		return (DBL_MAX * 2);
	if (defineType(input) == CHAR)
		return (static_cast<double>(input[0]));
	value = atof(input.c_str());
	if (value > FLT_MAX || value < -FLT_MAX)
		throw ScalarConverter::OutputNotToDisplay();
	return (static_cast<double>(value));
}

float	toFloat(std::string &input)
{
	double	value;

	if (input == "-inff" || input == "-inf")
		return (-FLT_MAX * 2);
	if (input == "+inff" || input == "+inf" || input == "inff" || input == "inf")
		return (FLT_MAX * 2);
	if (defineType(input) == CHAR)
		return (static_cast<float>(input[0]));
	value = atof(input.c_str());
	if (value > FLT_MAX || value < -FLT_MAX)
		throw ScalarConverter::OutputNotToDisplay();
	return (static_cast<float>(atof(input.c_str())));
}

char	toChar(std::string &input)
{
	double	value;
	char	c;

	if (defineType(input) == CHAR)
		return (static_cast<float>(input[0]));
	value = atof(input.c_str());
	if (value > CHAR_MAX || value < CHAR_MIN)
		throw ScalarConverter::ConversionImpossible();
	c = static_cast<char>(value);
	if (std::isprint(c))
		return (c);
	else
		throw(ScalarConverter::OutputNotToDisplay());
}
const std::string whichType(int type)
{
	switch (type)
	{
	case CHAR:
		return ("CHAR");
	case INT:
		return ("INT");
	case FLOAT:
		return ("FLOAT");
	case DOUBLE:
		return ("DOUBLE");
	}
	return ("NONE");
}

void ScalarConverter::convert(std::string &input)
{
	int	len;
	int	out;

	len = input.length();
	if (len == 0)
	{
		std::cerr << RED << "Error: Input length can't be zero." << RESET << std::endl;
		exit(1);
	}
	for (int i = 0; i < len; i++)
	{
		if (!isprint(input[i]))
		{
			std::cerr << RED << "Error: Input contains non-printable characters." << RESET << std::endl;
			exit(1);
		}
	}
	out = defineType(input);
	std::cout << YELLOW << "DEFINED TYPE IS: " << whichType(out) << RESET << std::endl;
	try
	{
		std::cout << CYAN << "CONVERT TO CHAR: " << RESET << GREEN << toChar(input) << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	try
	{
		std::cout << CYAN << "CONVERT TO INT: " << RESET << GREEN << toInt(input) << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	try
	{
		float f = toFloat(input);

		std::cout << CYAN << "CONVERT TO FLOAT: " << RESET << GREEN << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f" << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
	try
	{
		double d = toDouble(input);
		std::cout << CYAN << "CONVERT TO DOUBLE: " << RESET << GREEN<< d ;
		if (d == static_cast<int>(d))
			std::cout << ".0";
		std::cout << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
}

const char *ScalarConverter::NonExistentType::what(void) const throw()
{
	return ("Given type does not exist.");
}
const char *ScalarConverter::ConversionImpossible::what(void) const throw()
{
	return ("Conversion is impossible. ");
}
const char *ScalarConverter::OutputNotToDisplay::what(void) const throw()
{
	return ("Output can't be displayed.");
}