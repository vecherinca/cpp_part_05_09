//
// Created by Мария on 07/04/2024.
//

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm:public AForm {

	public:
		RobotomyRequestForm(std::string const _target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &cls);
		RobotomyRequestForm &operator=(Bureaucrat const &cls);
		int execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};


#endif 
