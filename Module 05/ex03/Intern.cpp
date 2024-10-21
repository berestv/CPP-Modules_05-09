#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {

}

Intern::Intern(const Intern &in) {

}

Intern &Intern::operator=(const Intern &in) {
	return *this;
}

Intern::~Intern() {

}

// FUNCTIONS

AForm *Intern::makeForm(const std::string& fName, const std::string& target) {
	try {
		if (target.empty())
			throw WrongArgsException();

		std::string strForms[3] = { "presidential pardon", "robotomy request", "shrubbery creation" };
		int idx = 0;
		for (int i = 0; i < 3; i++) {
			if (strForms[i] == target)
				idx = i;
		}

		switch (idx) {
			case 0:
				return new PresidentialPardonForm(target);
			case 1:
				return new RobotomyRequestForm(target);
			case 2:
				return new ShrubberyCreationForm(target);
			default:
				throw WrongArgsException();
		}
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

const char *Intern::WrongArgsException::what() const throw() {
	return "Wrong arguments! Please try again.";
}