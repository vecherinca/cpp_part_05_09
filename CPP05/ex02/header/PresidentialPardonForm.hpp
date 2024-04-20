
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm{

	public:
		PresidentialPardonForm(std::string const _target);
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &cls);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &cls);
		int execute(Bureaucrat const & executor) const;

	private:
		std::string _target;

};


#endif 
