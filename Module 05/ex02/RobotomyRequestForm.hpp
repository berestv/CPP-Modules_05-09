#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class RobotomyRequestForm : AForm {
private:
	std::string target;

public:
	RobotomyRequestForm(std::string trgt);
	RobotomyRequestForm(const RobotomyRequestForm& rrf);
	RobotomyRequestForm &operator=(const RobotomyRequestForm& rrf);
	~RobotomyRequestForm();

	static bool russianRoulette();
	void execute(Bureaucrat const & executor) const;
};

#endif //ROBOTOMYREQUESTFORM_HPP
