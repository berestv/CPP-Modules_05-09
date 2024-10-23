#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& sc);
	ScalarConverter &operator=(const ScalarConverter& sc);
	~ScalarConverter();

public:
	virtual void convert(std::string stRep);

	class InvalidInputExc : std::exception {
	public:
		virtual const char * what() const throw();
	};
};

#endif //SCALARCONVERTER_HPP
