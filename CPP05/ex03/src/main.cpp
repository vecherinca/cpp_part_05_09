#include "../header/Bureaucrat.hpp"
#include <iostream>
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/Intern.hpp"



int main() {
    // Setup colored output
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string RESET = "\033[0m";

    // Create an Intern and a high-grade Bureaucrat
    Intern someIntern;
    Bureaucrat chiefBureaucrat("Chief", 1);  

    AForm *shrubberyForm = NULL, *robotomyForm = NULL, *pardonForm = NULL, *nonExistentForm = NULL;

    try {
        // Intern creates various forms, including one that does not exist
        std::cout << GREEN << "Intern attempts to create three valid forms." << RESET << std::endl;
        shrubberyForm = someIntern.makeForm("shrubbery creation", "HomeGarden");
        robotomyForm = someIntern.makeForm("robotomy request", "PatientXYZ");
        pardonForm = someIntern.makeForm("presidential pardon", "CitizenA");

        std::cout << YELLOW << "Intern attempts to create a non-existent form." << RESET << std::endl;
        nonExistentForm = someIntern.makeForm("time travel application", "FutureEvent");

        // This line will not be reached if the previous form creation throws an exception
        std::cout << GREEN << "Non-existent form created successfully. This message should not appear." << RESET << std::endl;
    } catch (std::exception& e) {
        // Handle exceptions from non-existent form creation
        std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
    }

    try {
        // Bureaucrat attempts to sign and execute the valid forms if they were successfully created
        if (shrubberyForm) {
            chiefBureaucrat.signForm(*shrubberyForm);
            chiefBureaucrat.executeForm(*shrubberyForm);
        }
        if (robotomyForm) {
            chiefBureaucrat.signForm(*robotomyForm);
            chiefBureaucrat.executeForm(*robotomyForm);
        }
        if (pardonForm) {
            chiefBureaucrat.signForm(*pardonForm);
            chiefBureaucrat.executeForm(*pardonForm);
        }
    } catch (std::exception& e) {
        std::cerr << RED << "Execution Error: " << e.what() << RESET << std::endl;
    }

    // Cleanup dynamically allocated forms
    delete shrubberyForm;
    delete robotomyForm;
    delete pardonForm;
    delete nonExistentForm;  // This should be nullptr if creation failed

    return 0;
}
