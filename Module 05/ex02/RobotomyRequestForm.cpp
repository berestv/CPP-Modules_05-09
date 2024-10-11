#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string trgt) :
		AForm("RobotomyRequestForm", 72, 45), target(trgt) {
	std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) :
		AForm("RobotomyRequestForm", 72, 45), target(rrf.target) {
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf) {
	std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
	if (this != &rrf)
		this->target = rrf.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

// FUNCTIONS

bool RobotomyRequestForm::russianRoulette() {
	srand(static_cast<unsigned>(time(0)) ^ getpid());

	int rnd = rand();

	if (rnd % 2 == 0)
		return true;
	return false;
}