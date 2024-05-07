#include "Bureaucrat.hpp"
#include <iostream>

const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

int main() {
    try {
        Bureaucrat john("Mashulik", 2); 
        std::cout << john.getName() << " is created with grade: " << john.getGrade() << std::endl;

        john.Increment(); 
        std::cout << "After increment, " << john.getName() << "'s grade is: " << john.getGrade() << std::endl;

        john.Increment(); 

    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr <<  RED << "Exception caught: " << e.what() << RESET<< std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr <<  RED << "Exception caught: " << e.what() << RESET<< std::endl;
    }

    try {
        Bureaucrat jane("Xavier Niel", 150); // Assume this is below the lowest grade
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
