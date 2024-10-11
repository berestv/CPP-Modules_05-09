#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{

	try {
		Bureaucrat BurA("other", 100);
		ShrubberyCreationForm FormA("Formâge A");
		std::cout << FormA;
		BurA.signForm(FormA);
		BurA.executeForm(FormA);
		std::cout << FormA << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "============" << std::endl;
	try {
		Bureaucrat BurA("other", 72);
		RobotomyRequestForm FormA("hellooo");
		std::cout << FormA << std::endl;
		FormA.beSigned(BurA);
		std::cout << FormA << std::endl;
		BurA.executeForm(FormA);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "============" << std::endl;
	try {
		Bureaucrat BurA("other", 24);
		PresidentialPardonForm FormA("hellooo");
		std::cout << FormA << std::endl;
		FormA.beSigned(BurA);
		BurA.executeForm(FormA);
		std::cout << FormA << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "============" << std::endl;

	std::cout << std::endl;
}