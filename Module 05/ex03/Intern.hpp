#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& in);
	Intern& operator=(const Intern& in);
	~Intern();

	AForm* makeForm(const std::string& fName, const std::string& target);

	class WrongArgsException : public std::exception {
	public:
		virtual const char *what() const throw();
	};

};

#endif //INTERN_HPP
