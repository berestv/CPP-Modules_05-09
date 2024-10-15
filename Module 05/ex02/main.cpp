#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main ()
{
	try {
		Bureaucrat steve("Steve", 140);
		ShrubberyCreationForm form28C("Tree");
		std::cout << std::endl;
		std::cout << steve;
		std::cout << form28C;

		steve.signForm(form28C);
		steve.executeForm(form28C);

		Bureaucrat highIQ("Steve", 1);
		highIQ.executeForm(form28C);

		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;


	try {
		Bureaucrat mike("Mike", 1);
		RobotomyRequestForm form28B("Bender");
		PresidentialPardonForm pardonMe("Waltuh");

		std::cout << std::endl;
		std::cout << mike;
		std::cout << form28B;

		mike.signForm(form28B);
		mike.executeForm(form28B);

		std::cout << std::endl;
		std::cout << std::endl;

		mike.executeForm(pardonMe);
		mike.signForm(pardonMe);
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}