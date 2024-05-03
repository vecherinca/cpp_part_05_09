#include "../header/Bureaucrat.hpp"
#include <iostream>
#include "../header/AForm.hpp"
#include "../header/ShrubberyCreationForm.hpp"
#include "../header/RobotomyRequestForm.hpp"
#include "../header/PresidentialPardonForm.hpp"
#include "../header/Intern.hpp"

const std::string RED = "\033[31m";
const std::string RESET = "\033[0m";


int main() {
    // Properly instantiate an Intern object.
    Intern *lowlyIntern = new Intern();
    
    // Safely use the Intern object.
    AForm *form = lowlyIntern->makeForm("shrubbery creation", "target");
    
    // Check if the form was created successfully before attempting to delete it.
    if (form != NULL) {
        delete form;
    }

    // Clean up the Intern object to prevent memory leaks.
    delete lowlyIntern;

    return 0;
}