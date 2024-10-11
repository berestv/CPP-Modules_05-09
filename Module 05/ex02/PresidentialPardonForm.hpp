#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
	std::string target;

public:
	PresidentialPardonForm(std::string trgt);
	PresidentialPardonForm(const PresidentialPardonForm& ppf);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& ppf);
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
};

#endif //PRESIDENTIALPARDONFORM_HPP
