#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
private:
	const std::string name;
	bool sign;
	const int sigGrade;
	const int excGrade;

	static void checkGrades(int sGrade, int xGrade);
public:
	Form();
	Form(const std::string& nm, int sGrade, int xGrade);
	Form(const Form& frm);
	Form &operator=(const Form& frm);
	~Form();

	std::string getName() const;
	bool isSigned() const;
	int getSigGrade() const;
	int getExcGrade() const;
	void beSigned(Bureaucrat& bureau);

	class GradeTooHighException : public std::exception {
	public:
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		virtual const char * what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif //FORM_HPP
