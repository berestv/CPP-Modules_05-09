#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Bureau"), grade(0) {

}

Bureaucrat::Bureaucrat(std::string nm, int grd) {
	this->name = nm;
	try {
		setGrade(grd);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &brcrt) {

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &brcrt) {

}

// FUNCTIONS

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high! What a genius.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low! IQ--0";
}

void Bureaucrat::setGrade(int grd) {
	if (grd >= 150)
		throw GradeTooLowException;
	else if (grd <= 0)
		throw GradeTooHighException;
	else
		this->grade = grd;
}