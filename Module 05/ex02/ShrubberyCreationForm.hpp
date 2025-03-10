#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {
private:
	std::string target;

public:
	ShrubberyCreationForm(std::string trgt);
	ShrubberyCreationForm(const ShrubberyCreationForm& scf);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& scf);
	~ShrubberyCreationForm();

	void execute(const Bureaucrat & executor) const;

	class CouldNotCreateFile : std::exception {
	public:
		virtual const char * what() const throw();
	};
};

#endif //SHRUBBERYCREATIONFORM_HPP
