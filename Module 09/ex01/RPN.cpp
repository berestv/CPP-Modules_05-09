#include "RPN.hpp"

#include <algorithm>

RPN::RPN(std::string operation) {
	if (operation.find_first_not_of(" 0123456789+-*/") != std::string::npos)
		throw ErrorException();

	std::stringstream ss(operation);
	std::string token;

	while (ss >> token) {
		if (token.find_first_not_of("0123456789") == std::string::npos)
			num.push(std::atoi(token.c_str()));
		else if (token.size() == 1 && token.find_first_not_of("+-*/") == std::string::npos)
			execute(token);
		else
			throw ErrorException();
	}
	if (num.size() > 1)
		throw ErrorException();

	std::cout << num.top() << std::endl;
}

RPN::RPN(const RPN &cpy) {
	this->num = cpy.num;
}

RPN &RPN::operator=(const RPN &cpy) {
	if (this != &cpy)
		this->num = cpy.num;
	return *this;
}

RPN::~RPN() {

}

// FUNCITONS

void RPN::execute(std::string &token) {
	if (num.size() < 2)
		throw ErrorException();

	int temp = 0;
	int num1 = num.top();
	num.pop();
	int num2 = num.top();
	num.pop();

	switch (token[0]) {
		case '+':
			temp = num2 + num1;
			break;
		case '-':
			temp = num2 - num1;
			break;
		case '*':
			temp = num2 * num1;
			break;
		case '/':
			if (num2 != 0)
				temp = num2 / num1;
			break;
		default:
			throw ErrorException();
	}
	num.push(temp);
	//std::cout << num2 << " " << token[0] << " " << num1 << " = " << temp << std::endl;		//DEBUG
}

// EXCEPTIONS

const char *RPN::ErrorException::what() const throw() {
	return "Error";
}

