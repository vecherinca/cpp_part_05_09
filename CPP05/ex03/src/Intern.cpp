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
	(void) copy;

	return (*this);
}

const char *Intern::FormDoesNotExists::what(void) const throw()
{
    return ("Intern::exception: Form does not exist. :(");
}

AForm* createShrubberyCreationForm(const std::string& target) {
    return (new ShrubberyCreationForm(target));
}

AForm* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, std::string target){

	AForm *Form;

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
			Form = formCreationFuncs[i](target);
			return(Form);
			
		}
			
	}
	throw FormDoesNotExists();
}