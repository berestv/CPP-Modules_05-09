#include "Form.hpp"

Form::Form() : name("Default"), sign(false), sigGrade(1), excGrade(1){
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string nm, const int sGrade, const int xGrade) : name(nm), sigGrade(sGrade), excGrade(xGrade) {
	std::cout << "Form constructor called" << std::endl;
	if ()
}