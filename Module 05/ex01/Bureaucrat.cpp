#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("DefBureau"), grade(150) {
	std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string nm, int grd) : name(nm), grade(grd) {
	std::cout << "Bureaucrat constructor called." << std::endl;
	setGrade(grd);
	/*try {
		setGrade(grd);
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}*/
}

Bureaucrat::Bureaucrat(const Bureaucrat &brcrt) : name(brcrt.name), grade(brcrt.grade) {
	std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &brcrt) {
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	if (this != &brcrt)
	{
		try {
			setGrade(brcrt.grade);
		}
		catch (const Bureaucrat::GradeTooHighException& e) {
			std::cerr << e.what() << std::endl;
		}
		catch (const Bureaucrat::GradeTooLowException& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called." << std::endl;
}

// FUNCTIONS

std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::setGrade(int grd) {
	if (grd > 150)
		throw GradeTooLowException();
	else if (grd <= 0)
		throw GradeTooHighException();
	else
		this->grade = grd;
}

void Bureaucrat::signForm(AForm& frm) {
	try {
		frm.beSigned(*this);
		std::cout << frm.getName() << " was signed by " << this->getName() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << this->getName() << " couldn't sign " << frm.getName() << " because: " << e.what() << std::endl;
	}
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
	return *this;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high! What a genius.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low! IQ--";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}