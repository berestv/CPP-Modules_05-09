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

int decimals(double num){
	double deci = num - floor(num);
	std::ostringstream oss;
	oss << deci;
	int count;

	if (deci == 0)
		count = 1;
	else
		count = static_cast<int>(oss.str().length()) - 2;
	return count;
}

void print(double dbl, bool isDig) {
	// CHAR
	std::cout << "char: ";
	if (!isDig)
		std::cout << "impossible" << std::endl;
	else if (dbl < 32 || dbl > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(dbl) << "'" << std::endl;

	// INT
	std::cout << "int: ";
	if (dbl > 2147483647 || static_cast<long int>(dbl) < -2147483648)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(dbl) << std::endl;

	int deci = decimals(dbl);
	// FLOAT
	std::cout << "float: ";
	std::cout << std::fixed << std::setprecision(deci) << static_cast<float>(dbl) << "f" << std::endl;

	// DOUBLE
	std::cout << "double: ";
	std::cout << std::fixed << std::setprecision(deci) << dbl << std::endl;
}

void ScalarConverter::convert(std::string stRep) {
	char* endptr = NULL;
	bool isDig = true;

	for (int i = 0; i < static_cast<int>(stRep.length()); i++) {
		if (stRep[i] == ',')
			stRep[i] = '.';
		if (!isdigit(stRep[i]) && stRep[i] != '.' && stRep[i] != 'f')
			isDig = false;
	}
	double dbl = std::strtod(stRep.c_str(), &endptr);
	
	if ((*endptr != '\0' && strcmp("f", endptr) != 0))
		throw ScalarConverter::InvalidInputExc();

	print(dbl, isDig);
}

const char *ScalarConverter::InvalidInputExc::what() const throw() {
	return "Invalid input! You need to enter one argument: a number or a pseudo literal.";
}
