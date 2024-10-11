#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), sign(false), sigGrade(1), excGrade(1){
	std::cout << "Form default constructor called." << std::endl;
}

Form::Form(const std::string& nm, const int sGrade, const int xGrade) : name(nm), sign(false), sigGrade(sGrade), excGrade(xGrade) {
	std::cout << "Form constructor called." << std::endl;
	checkGrades(sGrade, xGrade);
}

Form::Form(const Form &frm) : name(frm.name), sign(frm.sign), sigGrade(frm.sigGrade), excGrade(frm.excGrade) {
	std::cout << "Form copy constructor called." << std::endl;
}

Form &Form::operator=(const Form &frm) {
	std::cout << "Form copy assignment operator called." << std::endl;
	if(this == &frm)
		this->sign = frm.sign;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

// FUNCTIONS

std::string Form::getName() const {
	return this->name;
}

bool Form::isSigned() const {
	return sign;
}

int Form::getSigGrade() const {
	return this->sigGrade;
}

int Form::getExcGrade() const {
	return this->excGrade;
}

void Form::beSigned(Bureaucrat& bureau) {
	if (this->sigGrade < bureau.getGrade())
		throw Form::GradeTooLowException();

	this->sign = true;
}

void Form::checkGrades(int sGrade, int xGrade) {
	if (sGrade <= 0 || xGrade <= 0)
		throw Form::GradeTooHighException();
	else if (sGrade > 150 || xGrade > 150)
		throw Form::GradeTooLowException ();
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high, nobody would be able to sign this...not even the president.";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low, this is a security risk since everyone can sign it.";
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << "Form: " << obj.getName() << ". Sign Grade: " << obj.getSigGrade() <<
	". Execution Grade: " << obj.getExcGrade() << "." << std::endl;
	return os;
};
