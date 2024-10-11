#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string trgt) :
AForm("ShruberryCreationForm", 145, 137), target(trgt) {
	std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &scf) :
AForm("ShruberryCreationForm", 145, 137), target(scf.target) {
	std::cout << "ShrubberyCreationForm copy constructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &scf) {
	if (this != &scf)
		this->target = scf.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

// FUNCTIONS

void ShrubberyCreationForm::execute(const Bureaucrat &bureau) const {
	try {
		if (bureau.getGrade() < this->getExcGrade() || !this->isSigned())
			throw AForm::GradeTooLowException();
		std::string filename = this->target;
		filename.append("_shrubbery");

		std::ofstream shrubTree(filename.c_str());

		if (!shrubTree.is_open())
			throw ShrubberyCreationForm::CouldNotCreateFile();

		shrubTree << "---------------------      ASCII TREE!      ---------------------" << std::endl;
		shrubTree << "                                                         .       " << std::endl;
		shrubTree << "                                              .         ;        " << std::endl;
		shrubTree << "                 .              .              ;%     ;;         " << std::endl;
		shrubTree << "                   ,           ,                :;%  %;          " << std::endl;
		shrubTree << "                    :         ;                   :;%;'     .,   " << std::endl;
		shrubTree << "           ,.        %;     %;            ;        %;'    ,;     " << std::endl;
		shrubTree << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'      " << std::endl;
		shrubTree << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'       " << std::endl;
		shrubTree << "               ;%;      %;        ;%;        % ;%;  ,%;'         " << std::endl;
		shrubTree << "                `%;.     ;%;     %;'         `;%%;.%;'           " << std::endl;
		shrubTree << "                 `:;%.    ;%%. %@;        %; ;@%;%'              " << std::endl;
		shrubTree << "                    `:%;.  :;bd%;          %;@%;'                " << std::endl;
		shrubTree << "                      `@%:.  :;%.         ;@@%;'                 " << std::endl;
		shrubTree << "                        `@%.  `;@%.      ;@@%;                   " << std::endl;
		shrubTree << "                          `@%%. `@%%    ;@@%;                    " << std::endl;
		shrubTree << "                            ;@%. :@%%  %@@%;                     " << std::endl;
		shrubTree << "                              %@bd%%%bd%%:;                      " << std::endl;
		shrubTree << "                                #@%%%%%:;;                       " << std::endl;
		shrubTree << "                                %@@%%%::;                        " << std::endl;
		shrubTree << "                                %@@@%(o);   /``                  " << std::endl;
		shrubTree << "                                %@@@o%;:(.~'                     " << std::endl;
		shrubTree << "                            `;. %@@@o%::;                        " << std::endl;
		shrubTree << "                               `)@@@o%::;                        " << std::endl;
		shrubTree << "                                %@@(o)::;                        " << std::endl;
		shrubTree << "                               .%@@@@%::;                        " << std::endl;
		shrubTree << "                               ;%@@@@%::;.                       " << std::endl;
		shrubTree << "                              ;%@@@@%%:;;;.                      " << std::endl;
		shrubTree << "                          ...;%@@@@@%%:;;;;,..                   " << std::endl;
		shrubTree << "-----------------------------------------------------------------" << std::endl;

		shrubTree.close();

		std::cout << "Shrubbery tree created successfully. CO2 is no more." << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Could not execute order 66: " << e.what() << std::endl;
	}
}

const char *ShrubberyCreationForm::CouldNotCreateFile::what() const throw() {
	return "Could not create file. Please ensure the file name is unique.";
}