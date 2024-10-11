#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	try {
		std::cout << "Try 1: " << std::endl;
		Bureaucrat stan("Stan", 75);
		Form form101("101", 74, 5);
		std::cout << std::endl;

		std::cout << stan;
		std::cout << form101;
		stan.signForm(form101);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "Try 2: " << std::endl;
		Bureaucrat mike("Mike", 1);
		Form form416("416", 50, 5);
		std::cout << std::endl;

		std::cout << mike;
		std::cout << form416;
		mike.signForm(form416);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what();
	}

	std::cout << std::endl;
}