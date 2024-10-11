#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
private:
	const std::string name;
	bool sign;
	const int sigGrade;
	const int excGrade;

	static void checkGrades(int sGrade, int xGrade);
public:
	AForm();
	AForm(const std::string& nm, int sGrade, int xGrade);
	AForm(const AForm& frm);
	AForm &operator=(const AForm& frm);
	~AForm();

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

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif //FORM_HPP
