#include "RPN.hpp"

RPN::RPN(std::string operation) {
	if (operation.find_first_not_of(" 0123456789+-*/") != std::string::npos)
		throw ErrorException();

}


// EXCEPTIONS

const char *RPN::ErrorException::what() const throw() {
	return "Error";
}

