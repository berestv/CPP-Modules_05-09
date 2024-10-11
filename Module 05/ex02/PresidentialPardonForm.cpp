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
	try {
		if (executor.getGrade() < this->getExcGrade() || !this->isSigned())
			throw Bureaucrat::GradeTooLowException();

		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Could not execute order 66: " << e.what() << std::endl;
	}
}
