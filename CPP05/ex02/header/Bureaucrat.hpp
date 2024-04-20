//
// Created by Мария on 23/03/2024.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat {

    private:
        std::string _name;
        int         _grade;
        Bureaucrat();
    public:
        Bureaucrat(std::string _name, int grade); 
        ~Bureaucrat(); 
        Bureaucrat(Bureaucrat const &cls); 
        Bureaucrat & operator=(Bureaucrat const & obj); 
        std::string getName() const;

        int getGrade() const; 
        void Increment(); 
        void Decrement(); 
        void    signForm(AForm &AForm);
        void    executeForm(AForm const & form);
        class	GradeTooHighException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class	GradeTooLowException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
    };

std::ostream & operator<<(std::ostream & o, Bureaucrat const & obj);

#endif