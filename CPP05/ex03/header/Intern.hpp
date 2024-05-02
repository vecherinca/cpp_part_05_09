#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
class Intern {

    private:

    public:
		Intern();
		~Intern();

		Intern(const Intern& copy);
		Intern& operator=(const Intern& copy);
		AForm* makeForm(std::string name, std::string target);
		
      
    };
