#include "Form.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), sign(false), sigGrade(1), excGrade(1){
	std::cout << "AForm default constructor called." << std::endl;
}

AForm::AForm(const std::string& nm, const int sGrade, const int xGrade) : name(nm), sign(false), sigGrade(sGrade), excGrade(xGrade) {
	std::cout << "AForm constructor called." << std::endl;
	checkGrades(sGrade, xGrade);
}

AForm::AForm(const AForm &frm) : name(frm.name), sign(frm.sign), sigGrade(frm.sigGrade), excGrade(frm.excGrade) {
	std::cout << "AForm copy constructor called." << std::endl;
}

AForm &AForm::operator=(const AForm &frm) {
	std::cout << "AForm copy assignment operator called." << std::endl;
	if(this == &frm)
		*this = frm;
	return *this;
}

AForm::~AForm() {
	std::cout << "AForm destructor called" << std::endl;
}

// FUNCTIONS

std::string AForm::getName() const {
	return this->name;
}

bool AForm::isSigned() const {
	return sign;
}

int AForm::getSigGrade() const {
	return this->sigGrade;
}

int AForm::getExcGrade() const {
	return this->excGrade;
}

void AForm::beSigned(Bureaucrat& bureau) {
	try {
		Bureaucrat::signForm(bureau, *this);
		this->sign = true;
	}
	catch (const std::exception &e) {
		std::cerr << bureau.getName() << " couldn't sign " << this->getName() << " because: " << e.what() << std::endl;
	}
}

void AForm::checkGrades(int sGrade, int xGrade) {
	if (sGrade <= 0 || xGrade <= 0)
		throw AForm::GradeTooHighException();
	else if (sGrade > 150 || xGrade > 150)
		throw AForm::GradeTooLowException ();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high, nobody would be able to sign this...not even the president.";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low, this is a security risk since everyone can sign it.";
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "AForm: " << obj.getName() << ". Sign Grade: " << obj.getSigGrade() <<
	". Execution Grade: " << obj.getExcGrade() << "." << std::endl;
	return os;
};
