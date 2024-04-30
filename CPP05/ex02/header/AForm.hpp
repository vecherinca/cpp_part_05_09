#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <ctime>
# include <fstream>
class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        int _grade_to_sign;
        int _grade_to_execute;
    public:
        AForm(std::string name, int gradeToSign, int initGradeExec); 
        AForm(const AForm &copy); 
        AForm &operator=(const AForm &copy); 
        ~AForm();
        std::string getName() const; 
        bool        getSigned() const; 
        int         getGradeToSign() const; 
        int         getGradeToExecute() const; 
        void        beSigned(const Bureaucrat& bureaucrat); 
        virtual int execute(Bureaucrat const & executor) const = 0;


        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm);

#endif
