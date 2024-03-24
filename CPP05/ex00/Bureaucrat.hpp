//
// Created by Мария on 23/03/2024.
//

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150
#include <iostream>

class Bureaucrat {

    private:
        std::string _name;
        int         _grade;
    public:
        Bureaucrat(); //done
        Bureaucrat(std::string _name, int grade); //done
        ~Bureaucrat(); //done
        Bureaucrat(Bureaucrat const &cls); //done
        Bureaucrat & operator=(Bureaucrat const & obj); //done
        std::string getName() const;//done
        int getGrade() const; //done
        void Increment(); //done
        void Decrement(); //done
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

#endif //BUREAUCRAT_HPP
