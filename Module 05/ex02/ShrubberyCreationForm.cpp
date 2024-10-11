#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string trgt) :
AForm("ShruberryCreationForm", 145, 137), target(trgt) {
	std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) :
AForm("ShruberryCreationForm", 145, 137), target(scf.target) {
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf) {
	if (this != &scf)
		this->target = scf.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

// FUNCTIONS

void ShrubberyCreationForm::execute(const Bureaucrat &bureau) const {

}
