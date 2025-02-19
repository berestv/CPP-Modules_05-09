#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>

class RPN {

public:
	RPN(std::string operation);
	RPN(const RPN &cpy);
	RPN &operator=(const RPN &cpy);


	class ErrorException : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif //RPN_HPP
