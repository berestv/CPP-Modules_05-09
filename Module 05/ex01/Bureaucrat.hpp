#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string name;
	int grade;

	void setGrade(int grd);
public:
	Bureaucrat();
	Bureaucrat(std::string nm, int grd);
	Bureaucrat(const Bureaucrat& brcrt);
	Bureaucrat &operator=(const Bureaucrat& brcrt);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;
	void signForm(Form& frm);

	Bureaucrat operator++();
	Bureaucrat operator--();

	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const throw();
	};

class GradeTooLowException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif // BUREAUCRAT_HPP
