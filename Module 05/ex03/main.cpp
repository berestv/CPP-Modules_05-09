#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main ()
{
	try {
		Bureaucrat steve("Steve", 140);

		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << std::endl;
		std::cout << steve;
		std::cout << rrf;

		steve.signForm(*rrf);
		steve.executeForm(*rrf);

		Bureaucrat highIQ("HiQ", 1);
		highIQ.executeForm(*rrf);

		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

/*	try {
		Bureaucrat mike("Mike", 1);
		Bureaucrat dmb("Dumbureau", 150);
		RobotomyRequestForm form28B("Bender");
		PresidentialPardonForm pardonMe("Waltuh");

		std::cout << std::endl;
		std::cout << mike;
		std::cout << form28B;

		dmb.signForm(form28B);
		mike.signForm(form28B);
		mike.executeForm(form28B);

		std::cout << std::endl;
		std::cout << std::endl;

		mike.executeForm(pardonMe);
		mike.signForm(pardonMe);
		mike.executeForm(pardonMe);
		std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}*/
}