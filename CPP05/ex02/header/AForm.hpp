#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include <random>
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
        //AForm(); // done
        AForm(std::string name, int gradeToSign, int initGradeExec); //done
        AForm(const AForm &copy); //done
        AForm &operator=(const AForm &copy); //done
        ~AForm();
        std::string getName() const; //done
        bool        getSigned() const; //done
        int         getGradeToSign() const; //done
        int         getGradeToExecute() const; //done
        void        beSigned(const Bureaucrat& bureaucrat); //done
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
