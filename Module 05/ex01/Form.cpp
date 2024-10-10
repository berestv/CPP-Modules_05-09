#include "Form.hpp"

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
		*this = frm;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

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

// FUNCTIONS

void Form::checkGrades(int sGrade, int xGrade) {
	if (sGrade <= 0 || xGrade <= 0)
		throw Form::GradeTooHighException();
	else if (sGrade > 150 || xGrade > 150)
		throw Form::GradeTooLowException ();
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << "Form: " << obj.getName() << ". Sign Grade: " << obj.getSigGrade() <<
	". Execution Grade: " << obj.getExcGrade() << "." << std::endl;
	return os;
};