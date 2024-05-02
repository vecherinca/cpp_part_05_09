#include "../header/Intern.hpp"

Intern::Intern()
{
	std::cout << "[Intern initialised]" << std::endl;
}

Intern::~Intern()
{
	std::cout << "[Intern destroyed]" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	std::cout << "Copy of [Intern] created" << std::endl;
	*this = copy;
}
Intern &Intern::operator=(const Intern& copy)
{
	if (this == &copy)
		return (*this);

	return (*this);
}

AForm* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target){

	typedef AForm* (*FormCreationFunc)(const std::string&);
	std::string strings[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	 FormCreationFunc formCreationFuncs[3] = {
        &createShrubberyCreationForm,
        &createRobotomyRequestForm,
        &createPresidentialPardonForm
    };

	for (int i = 0; i < 3; i++)
	{
		if (strings[i] == name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return (formCreationFuncs[i](target));
		}
			
	}
	
	std::cout << "Intern can't create " << name <<  '\n';
	return(NULL);
}