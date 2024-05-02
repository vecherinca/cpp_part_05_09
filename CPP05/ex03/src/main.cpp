#include "../header/Bureaucrat.hpp"
#include <iostream>
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/Intern.hpp"

const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

void printInColor(const std::string &message, const std::string &color) {
    std::cout << color << message << "\033[0m" << std::endl;
}

int main() {

    {
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "TEST");
        delete rrf;
	}


}