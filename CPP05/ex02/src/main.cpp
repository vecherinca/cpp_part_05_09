#include "../header/Bureaucrat.hpp"
#include <iostream>
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";

void printInColor(const std::string &message, const std::string &color) {
    std::cout << color << message << "\033[0m" << std::endl;
}

int main() {
    const std::string red = "\033[1;31m";
    const std::string green = "\033[1;32m";
    const std::string yellow = "\033[1;33m";

    // Creating bureaucrats
    Bureaucrat highRanked("Alice", 1); // High rank, can execute any form
    Bureaucrat midRanked("Bob", 50);   // Middle rank, for testing limits
    Bureaucrat lowRanked("Charlie", 150); // Low rank, should fail most executions

    // Creating forms
    ShrubberyCreationForm shrub("Garden");
    RobotomyRequestForm robot("Employee");
    PresidentialPardonForm pardon("Citizen");

    try {
     
        highRanked.signForm(shrub);
        highRanked.executeForm(shrub);
        printInColor("ShrubberyCreation executed by high ranked bureaucrat: Success", green);

        highRanked.signForm(robot);
        highRanked.executeForm(robot);
        printInColor("RobotomyRequest executed by high ranked bureaucrat: Success", green);

        highRanked.signForm(pardon);
        highRanked.executeForm(pardon);
        printInColor("PresidentialPardon executed by high ranked bureaucrat: Success", green);

        midRanked.signForm(robot);  
        midRanked.executeForm(robot);
        printInColor("RobotomyRequest executed by mid ranked bureaucrat: Should fail", yellow);

        lowRanked.signForm(shrub);  
        lowRanked.executeForm(shrub);
        printInColor("ShrubberyCreation executed by low ranked bureaucrat: Should fail", yellow);

    } catch (std::exception &e) {
        printInColor(std::string("Exception: ") + e.what(), red);
    }

    return 0;
}