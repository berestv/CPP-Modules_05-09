#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <unistd.h>

class RobotomyRequestForm : AForm {
private:
	const std::string name;
	std::string target;
	bool sign;
	const int sigGrade;
	const int excGrade;

public:
	RobotomyRequestForm(std::string trgt);
	RobotomyRequestForm(const RobotomyRequestForm& rrf);
	RobotomyRequestForm &operator=(const RobotomyRequestForm& rrf);
	~RobotomyRequestForm();
	static bool russianRoulette();

};

#endif //ROBOTOMYREQUESTFORM_HPP
