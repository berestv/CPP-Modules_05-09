#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string trgt) : name("RobotomyRequestForm"), target(trgt), sign(false), sigGrade(72), excGrade(45) {
	std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rrf) :
name(rrf.name), target(rrf.target), sign(rrf.isSigned()), sigGrade(rrf.sigGrade), excGrade(rrf.excGrade) {
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rrf) {
	std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
	if (this != &rrf)
	{
		this->target = rrf.target;
		this->sign = rrf.sign;
	}
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