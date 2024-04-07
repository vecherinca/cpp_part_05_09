#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _signed;
        int _grade_to_sign;
        int _grade_to_execute;
    public:
        //Form(); // done
        Form(std::string name, int gradeToSign, int initGradeExec); //done
        Form(const Form &copy); //done
        Form &operator=(const Form &copy); //done
        ~Form();
        std::string getName() const; //done
        bool        getSigned() const; //done
        int         getGradeToSign() const; //done
        int         getGradeToExecute() const; //done
        void        beSigned(const Bureaucrat& bureaucrat); //done


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

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
