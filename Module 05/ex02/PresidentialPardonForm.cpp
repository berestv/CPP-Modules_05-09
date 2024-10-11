#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string trgt) :
		AForm("PresidentialPardonForm", 25, 5), target(trgt) {
	std::cout << "PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ppf) :
		AForm("PresidentialPardonForm", 25, 5), target(ppf.target) {
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ppf) {
	if (this != &ppf)
		this->target = ppf.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

// FUNCTIONS

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	
}