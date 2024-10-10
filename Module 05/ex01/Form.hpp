#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form {
private:
	const std::string name;
	bool sign;
	const int sigGrade;
	const int excGrade;

public:
	Form();
	Form(std::string nm, const int sGrade, const int xGrade);
	Form(const Form& frm);
	Form &operator=(const Form& frm);
	~Form();

	std::string getName();
	bool isSigned();
	int getSigGrade();
	int getExcGrade();

	using GradeTooHighException = Bureaucrat::GradeTooHighException;
	using GradeTooLowException = Bureaucrat::GradeTooLowException;

}
std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif //FORM_HPP
