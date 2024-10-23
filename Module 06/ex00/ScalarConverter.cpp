#include "ScalarConverter.hpp"
#include <cstdlib>

ScalarConverter::ScalarConverter() {

}

ScalarConverter::ScalarConverter(const ScalarConverter &sc) {

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc) {

}

ScalarConverter::~ScalarConverter() {

}

// FUNCTIONS

void ScalarConverter::convert(std::string stRep) {
	//std::string lit[6] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" };
	//float flt = strtof(stRep.c_str(), NULL);

	double dbl = strtod(stRep.c_str(), NULL);

}

const char *ScalarConverter::InvalidInputExc::what() const throw() {
	return "Invalid input! You need to enter one argument: a number or a pseudo literal.";
}