#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm:public AForm {

	public:
		RobotomyRequestForm(std::string const _target);
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &cls);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &cls);
		int execute(Bureaucrat const & executor) const;

	private:
		std::string _target;
};


#endif 
