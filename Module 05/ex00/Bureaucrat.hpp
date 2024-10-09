#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

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

	std::string getName();
	int getGrade();

	Bureaucrat operator++();
	Bureaucrat operator--();

	std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

	class GradeTooHighException {
	public:
		virtual const char * what() const throw();
	};
	class GradeTooLowException {
	public:
		virtual const char * what() const throw();
	};
};

#endif // BUREAUCRAT_HPP
