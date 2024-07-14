#include "../headers/ScalarConverter.hpp"

int main(int ac, char **av)
{
    try{
        if (ac == 2)
        {
            std::string arg(av[1]);
            ScalarConverter::convert(arg);
        }
        else
            std::cout << "Please launch with the correct argument." << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << std::string("Exception: ") << e.what() << std::endl;
    }

	return (0);
}