#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureau"), grade(150) {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string nm, int grd) : name(nm) {
	std::cout << "Bureaucrat constructor called." << std::endl;
	try {
		setGrade(grd);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &brcrt) : name(brcrt.name), grade(brcrt.grade) {
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &brcrt) {
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	if (this != &brcrt)
		this->grade = brcrt.grade;
	return *this;
}

// FUNCTIONS

std::string Bureaucrat::getName() {
	return this->name;
}

int Bureaucrat::getGrade() {
	return this->grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high! What a genius.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low! IQ--";
}

void Bureaucrat::setGrade(int grd) {
	if (grd > 150)
		throw GradeTooLowException();
	else if (grd <= 0)
		throw GradeTooHighException();
	else
		this->grade = grd;
}

Bureaucrat Bureaucrat::operator++() {
	try {
		setGrade(this->grade - 1);
	}
	catch (const std::exception& e) {
		std::cerr << "Cannot increment grade. " << e.what() << std::endl;
	}
	return *this;
}

Bureaucrat Bureaucrat::operator--() {
	try {
		setGrade(this->grade + 1);
	}
	catch (const std::exception& e) {
		std::cerr << "Cannot decrement grade. " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj){
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}