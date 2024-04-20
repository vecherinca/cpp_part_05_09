
#include "../header/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const _target):AForm("PresidentialPardonForm", 25, 5), _target(_target)
{
	std::cout << "[PresidentialPardonForm] is created" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "[PresidentialPardonForm] is deprecated" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy):AForm(copy)
{
    this -> _target = copy._target;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &cls)
{
    if (this != &cls)
        this -> _target = cls._target;
    return(*this);
}

int PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
    {
        std::cout << "Form is not signed" << std::endl;
        return (1);
    }
    else if (this->getGradeToExecute() < executor.getGrade()){
        std::cout << "Bureucrat " << executor.getName() << " not qualified to sign this AForm." << std::endl;
        throw GradeTooLowException();
    }
    std::cout << this -> _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    return(0);
}