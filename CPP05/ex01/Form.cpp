#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExec): _name(name), _signed(false)
{
    std::cout << "[Form] Constructor initialisation..." << std::endl;

    if (gradeToSign < 1 || gradeToExec < 1 )
        throw GradeTooHighException();
    if (gradeToExec > 150 || gradeToSign > 150)
        throw  GradeTooLowException();
    this->_grade_to_sign = gradeToSign;
    this->_grade_to_execute = gradeToExec;
    std::cout << "[Form] Constructor called" << " with name: " << this ->_name << " with grade to sign: " << this ->_grade_to_sign << " with grade to exec: " << this ->_grade_to_execute <<std::endl;
}
Form::~Form(void)
{
    std::cout << this->_name << "[Form] got shredded and binned" << std::endl;
}
Form::Form(const Form &copy) {
    std::cout << "[Form] copied" << std::endl;
    *this = copy;
}

Form &Form::operator=(Form const &copy)
{
    this -> _signed = copy._signed;
    return(*this);
}

std::string Form::getName(void) const
{
    return (this->_name);
}

int Form::getGradeToSign(void) const
{
    return (this->_grade_to_sign);
}

int Form::getGradeToExecute(void) const
{
    return (this->_grade_to_execute);
}

bool Form::getSigned(void) const
{
    if (_signed)
        return(true);
    else
        return(false);
}

std::ostream &operator<<(std::ostream &out, Form const &obj)
{
    out << "📄" << obj.getName() << " [Form]:" << std::endl;
    out << "Status:" << obj.getSigned() << std::endl;
    out << "Grade to sign:" << obj.getGradeToSign() << std::endl;
    out << "Grade to execute:" << obj.getGradeToExecute() << std::endl;
    return (out);
}

void        Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (this->_signed == true)
        std::cout << "Form already signed." << std::endl;
    else if (this->_grade_to_sign < bureaucrat.getGrade()){
        std::cout << "Bureucrat " << bureaucrat.getName() << " not qualified to sign this form." << std::endl;
        throw GradeTooLowException();
    }
    else
    {
        this->_signed = true;
        std::cout << "Bureucrat " << bureaucrat.getName() << " has signed the " << this->_name << " form" << std::endl;
    }
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return("Sign to exec ot sign form is too low and cant sign this form");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
    return("Sign to exec ot sign form is too high should be between 1 & 150");
}