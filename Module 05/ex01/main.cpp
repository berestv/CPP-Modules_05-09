#include "Bureaucrat.hpp"

int main ()
{
	try {
		std::cout << "Try 1: " << std::endl;
		Bureaucrat gradeLow("Tu Lou", 150);

		std::cout << gradeLow;
		gradeLow.operator--();
		std::cout << gradeLow;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what();
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what();
	}

	std::cout << std::endl;

	try {
		std::cout << "Try 2: " << std::endl;
		Bureaucrat gradeHigh("Tu Hi", 1);

		std::cout << gradeHigh;
		gradeHigh.operator++();
		std::cout << gradeHigh;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what();
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what();
	}

	std::cout << std::endl;

	try {
		std::cout << "Try 3: " << std::endl;
		Bureaucrat gradeHigh("Tu Hi", 0);

		std::cout << gradeHigh;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what();
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what();
	}

	std::cout << std::endl;
	std::cout << std::endl;

	try {
		std::cout << "Try 4 [Normal]: " << std::endl;
		Bureaucrat gradeHigh("Mike", 5);

		std::cout << gradeHigh;
		gradeHigh.operator++();
		gradeHigh.operator++();
		gradeHigh.operator++();
		std::cout << gradeHigh;
		gradeHigh.operator--();
		std::cout << gradeHigh;
	}
	catch (Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what();
	}
	catch (Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what();
	}

	std::cout << std::endl;
}