#include "../header/Bureaucrat.hpp"
#include "../header/AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExec): _name(name), _signed(false)
{
    std::cout << "[AForm] Constructor initialisation..." << std::endl;

    if (gradeToSign < 1 || gradeToExec < 1 )
        throw GradeTooHighException();
    if (gradeToExec > 150 || gradeToSign > 150)
        throw  GradeTooLowException();
    this->_grade_to_sign = gradeToSign;
    this->_grade_to_execute = gradeToExec;
    std::cout << "[AForm] Constructor called" << " with name: " << this ->_name << " with grade to sign: " << this ->_grade_to_sign << " with grade to exec: " << this ->_grade_to_execute <<std::endl;
}
AForm::~AForm(void)
{
    std::cout << this->_name << "[AForm] got shredded and binned" << std::endl;
}
AForm::AForm(const AForm &copy) {
    std::cout << "[AForm] copied" << std::endl;
    *this = copy;
}

AForm &AForm::operator=(AForm const &copy)
{
    this -> _signed = copy._signed;
    return(*this);

}

std::string AForm::getName(void) const
{
    return (this->_name);
}

int AForm::getGradeToSign(void) const
{
    return (this->_grade_to_sign);
}

int AForm::getGradeToExecute(void) const
{
    return (this->_grade_to_execute);
}

bool AForm::getSigned(void) const
{
    if (_signed)
        return(true);
    else
        return(false);
}

std::ostream &operator<<(std::ostream &out, AForm const &obj)
{
    out << "📄" << obj.getName() << " [AForm]:" << std::endl;
    out << "Status:" << obj.getSigned() << std::endl;
    out << "Grade to sign:" << obj.getGradeToSign() << std::endl;
    out << "Grade to execute:" << obj.getGradeToExecute() << std::endl;
    return (out);
}

void        AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (this->_signed == true)
        std::cout << "AForm already signed bro" << std::endl;
    else if (this->_grade_to_sign < bureaucrat.getGrade()){
        std::cout << "Bureucrat " << bureaucrat.getName() << " not qualified to sign this AForm." << std::endl;
        throw GradeTooLowException();
    }
    else
    {
        this->_signed = true;
        std::cout << "Bureucrat " << bureaucrat.getName() << " has signed the " << this->_name << " AForm" << std::endl;
    }
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return("Sign to exec ot sign AForm is too low and cant sign this AForm");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return("Sign to exec ot sign AForm is too high should be between 1 & 150");
}