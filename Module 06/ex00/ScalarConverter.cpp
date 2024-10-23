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

void ScalarConverter::convert(std::string stRep) {


	double dbl = strtod(stRep.c_str(), NULL);
	float flt = strtof(stRep.c_str(), NULL);
}

const char *ScalarConverter::InvalidInputExc::what() const throw() {
	return "Invalid input! You need to enter a number or a pseudo literal.";
}