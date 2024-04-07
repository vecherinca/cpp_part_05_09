#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

int main() {
    try {
        Bureaucrat john("John Doe", 2);
        Form form("stupid form number 1", 2, 5);
        john.signForm(form);
        john.signForm(form);
        std::cout << "test: "<< john << std::endl;

    } catch (std::exception &e) {
        std::cerr <<  RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    return 0;
}
