#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stack>

class RPN {
private:
	std::stack<int> num;

public:
	RPN(std::string operation);
	RPN(const RPN &cpy);
	RPN &operator=(const RPN &cpy);
	~RPN();

	void execute(std::string &token);

	class ErrorException : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif //RPN_HPP
