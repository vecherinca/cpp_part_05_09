
#include "../header/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string const _target):AForm("ShrubberyCreationForm", 25, 5), _target(_target)
{
	std::cout << "[ShrubberyCreationForm] is created" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "[ShrubberyCreationForm] is deprecated" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy):AForm(copy)
{
    this -> _target = copy._target;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &cls)
{
    if (this != &cls)
        this -> _target = cls._target;
    return(*this);
}

int ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    std::fstream file;
    
    std::string filename = this->_target + "_shrubbery"; 
	if (this->getSigned() == false)
    {
        std::cout << "Form is not signed" << std::endl;
        return (1);
    }
    else if (this->getGradeToExecute() < executor.getGrade()){
        std::cout << "Bureucrat " << executor.getName() << " not qualified to sign this Form." << std::endl;
        throw GradeTooLowException();
    }
    file.open(filename.c_str(), std::fstream::out | std::fstream::trunc);
    if (!file.good())
        std::cerr << "Failed to open shrubbery target file: " << this->_target << std::endl;

    file << "      /\\      \n";
    file << "     /\\*\\     \n";
    file << "    /\\O\\*\\    \n";
    file << "   /*/\\/\\/\\   \n";
    file << "  /\\O\\/\\*\\/\\  \n";
    file << " /\\*\\/\\*\\/\\/\\ \n";
    file << "/\\O\\/\\/*/\\/O/\\\n";
    file << "      ||      \n";
    file << "      ||      \n";
    file << "      ||      \n";


    file.close();
    return(0);
}
