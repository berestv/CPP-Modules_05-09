#include "ScalarConverter.hpp"

int main (int argc, char *argv[])
{
	try {
		if (argc != 2)
			throw ScalarConverter::InvalidInputExc();

		ScalarConverter sConv;

		sConv.convert(argv[1]);
	}
	catch (const std::exception& e) {
		std::cerr << e.what()<< std::endl;
	}
}