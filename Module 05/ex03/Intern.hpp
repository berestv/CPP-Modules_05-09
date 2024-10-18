#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& in);
	Intern& operator=(const Intern& in);
	~Intern();

	AForm* makeForm(std::string fName, std::string target);
};

#endif //INTERN_HPP
