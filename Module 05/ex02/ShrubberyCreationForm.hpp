#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : AForm {
private:
	const std::string name;
	bool sign;
	const int sigGrade;
	const int excGrade;


public:
	static void checkGrades(int sGrade, int xGrade);

};

#endif //SHRUBBERYCREATIONFORM_HPP
