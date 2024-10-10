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

	void checkGrades(int sGrade, int xGrade);
public:
	Form();
	Form(const std::string& nm, const int sGrade, const int xGrade);
	Form(const Form& frm);
	Form &operator=(const Form& frm);
	~Form();

	std::string getName() const;
	bool isSigned() const;
	int getSigGrade() const;
	int getExcGrade() const;

	typedef Bureaucrat::GradeTooHighException GradeTooHighException;
	typedef Bureaucrat::GradeTooLowException GradeTooLowException;

};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif //FORM_HPP
