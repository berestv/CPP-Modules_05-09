#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <cmath>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& sc);
	ScalarConverter &operator=(const ScalarConverter& sc);

public:
	~ScalarConverter();

	static void convert(std::string stRep);

	class InvalidInputExc : public std::exception {
	public:
		virtual const char * what() const throw();
	};
};

#endif //SCALARCONVERTER_HPP
