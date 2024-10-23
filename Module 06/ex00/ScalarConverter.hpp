#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& sc);
	ScalarConverter &operator=(const ScalarConverter& sc);
	~ScalarConverter();

	virtual void convert(std::string stRep);

	class InvalidInputExc : std::exception {
	public:
		virtual const char * what() const throw();
	};
};

#endif //SCALARCONVERTER_HPP
