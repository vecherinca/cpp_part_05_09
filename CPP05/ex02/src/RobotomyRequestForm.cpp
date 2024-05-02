
#include "../header/RobotomyRequestForm.hpp"
#include <cstdlib>  // For rand() and srand()
#include <ctime>  

RobotomyRequestForm::RobotomyRequestForm(std::string const _target):AForm("RobotomyRequestForm", 72, 45), _target(_target)
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

    std::srand(std::time(NULL));

	if (this->getSigned() == false)
    {
        std::cout << "Form is not signed" << std::endl;
        return (1);
    }
    else if (this->getGradeToExecute() < executor.getGrade()){
        std::cout << "Bureucrat " << executor.getName() << " not qualified to sign this AForm." << std::endl;
        throw GradeTooLowException();
    }
    std::cout << "DRRRRRRRRRRRRR DRRRRR DRRR (It is a drilling noise)"<<std::endl;
    if (std::rand() % 2 == 0) { 
        std::cout << this -> _target << "The target has been robotomized successfully.\n";
    } else {
        std::cout << "The robotomy failed.\n";
    }
    return(0);
}
