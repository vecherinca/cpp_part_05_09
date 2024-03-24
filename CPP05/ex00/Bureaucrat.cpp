
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_name("None")
{
    this -> _grade = LOWEST_GRADE;
    std::cout << "Constructor Called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
    this -> _name = name;
    if (grade > LOWEST_GRADE)
        throw (Bureaucrat::GradeTooLowException());
    if (grade < HIGHEST_GRADE)
        throw (Bureaucrat::GradeTooHighException());
    this -> _grade = grade;
    std::cout << "Constructor Called with name initialised to " << this -> _name << "Grade is initialised to " << this -> _grade<< std::endl;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return ("Bureaucrat::exception: Grade is to high");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return ("Bureaucrat::exception: Grade is to low");
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & cls)
{
    std::cout << "Assignation operator called" << std::endl;
    if (cls._grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
    if (cls._grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
    if (this != &cls)
        this -> _grade = cls.getGrade();
    return(*this);
}

Bureaucrat::Bureaucrat(Bureaucrat const &cls)
{
    //std::cout << "Copy Constructor Called" << std::endl
    *this = cls;
}

int Bureaucrat::getGrade() const {
    return(this -> _grade);
}

std::string Bureaucrat::getName() const{
    return(this -> _name);
}

void Bureaucrat::Increment() {
    this ->_grade--;
    if (this -> _grade < HIGHEST_GRADE)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::Decrement() {
    this ->_grade++;
    if (this -> _grade > LOWEST_GRADE)
        throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj)
{
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
    return o;
}
