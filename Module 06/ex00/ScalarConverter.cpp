#include "ScalarConverter.hpp"

void ScalarConverter::convert(std::string stRep) {
	double dbl = atof(stRep.c_str());
	int intg = dbl;
	float flt = std::stof(stRep);
}