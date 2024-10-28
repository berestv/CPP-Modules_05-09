#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main ()
{
	try {
		Bureaucrat steve("Steve", 70);

		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << std::endl;
		std::cout << steve;
		std::cout << *rrf;

		steve.signForm(*rrf);
		steve.executeForm(*rrf);

		Bureaucrat highIQ("HiQ", 1);
		highIQ.executeForm(*rrf);

		std::cout << std::endl;
		delete rrf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}