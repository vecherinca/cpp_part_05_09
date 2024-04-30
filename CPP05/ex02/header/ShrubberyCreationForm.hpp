
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
class ShrubberyCreationForm: public AForm {

	public:
		ShrubberyCreationForm(std::string const _target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &cls);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &cls);
		int execute(Bureaucrat const & executor) const;
		
	private:
		std::string _target;
};


#endif 
