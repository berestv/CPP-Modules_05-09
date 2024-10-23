#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &sc) {
	(void)sc;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &sc) {
	(void)sc;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

// FUNCTIONS

void ScalarConverter::convert(std::string stRep) {
	//std::string lit[6] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" };
	//float flt = strtof(stRep.c_str(), NULL);
	char* endptr = NULL;
	double dbl = std::strtod(stRep.c_str(), &endptr);
	if ((*endptr != '\0' && strcmp("f", endptr) != 0) || dbl > 2147483647 || dbl < -2147483648)
		throw ScalarConverter::InvalidInputExc();

	std::cout << dbl << std::endl;
	std::cout << endptr << std::endl << std::endl;

}

const char *ScalarConverter::InvalidInputExc::what() const throw() {
	return "Invalid input! You need to enter one argument: a number or a pseudo literal.";
}