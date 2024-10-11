#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : AForm {
private:
	std::string target;

public:
	ShrubberyCreationForm(std::string trgt);
	ShrubberyCreationForm(const ShrubberyCreationForm& scf);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& scf);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat& bureau) const;
};

#endif //SHRUBBERYCREATIONFORM_HPP
