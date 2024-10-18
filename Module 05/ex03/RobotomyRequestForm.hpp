#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class RobotomyRequestForm : public AForm {
private:
	std::string target;

public:
	RobotomyRequestForm(std::string trgt);
	RobotomyRequestForm(const RobotomyRequestForm& rrf);
	RobotomyRequestForm &operator=(const RobotomyRequestForm& rrf);
	~RobotomyRequestForm();

	static bool russianRoulette();
	void execute(Bureaucrat const & executor) const;

class RobotomyFailed : public std::exception {
public:
	virtual const char * what() const throw();
};
};

#endif //ROBOTOMYREQUESTFORM_HPP
