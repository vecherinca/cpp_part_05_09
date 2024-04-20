
#include "../header/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const _target):AForm("RobotomyRequestForm", 25, 5), _target(_target)
{
	std::cout << "[RobotomyRequestForm] is created" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "[RobotomyRequestForm] is deprecated" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy):AForm(copy)
{
    this -> _target = copy._target;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &cls)
{
    if (this != &cls)
        this -> _target = cls._target;
    return(*this);
}

int RobotomyRequestForm::execute(Bureaucrat const & executor) const
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
