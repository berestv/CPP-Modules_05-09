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
		else if (token.size() == 1)
			ops.push(token);
		else
			throw ErrorException();
	}
	execute();
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

void RPN::execute() {
	if (num.size() != (ops.size() + 1))
		throw ErrorException();

	std::stack<std::string> tmpOps;
	while (!ops.empty()) {
		tmpOps.push(ops.top());
		ops.pop();
	}
	ops = tmpOps;

	std::stack<int> tmpNum;
	while (!num.empty()) {
		tmpNum.push(num.top());
		num.pop();
	}
	num = tmpNum;

	while (!ops.empty()) {
		int temp = num.top();
		std::cout << num.top() << " ";
		num.pop();

		switch (ops.top()[0]) {
			case '+':
				temp += num.top();
				break;
			case '-':
				temp -= num.top();
				break;
			case '*':
				temp *= num.top();
				break;
			case '/':
				if (temp != 0 || num.top() != 0) {
					temp /= num.top();
				} else
					ops.push("/");
				break;
			default:
				throw ErrorException();
		}
		std::cout << ops.top()[0] << " " << num.top() << " = " << temp;
		num.pop();
		ops.pop();

		num.push(temp);
		std::cout << " pushed back" << std::endl;
	}

	if (!ops.empty() || num.size() != 1)
		throw ErrorException();

	std::cout << num.top() << std::endl;
}

// EXCEPTIONS

const char *RPN::ErrorException::what() const throw() {
	return "Error";
}

