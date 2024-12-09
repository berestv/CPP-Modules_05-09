#include "Span.hpp"

Span::Span(unsigned int n) {
	if (n >= 0 && n <= 2147483647)
		max = n;
	else
		throw InvArgsException();
}

const char *Span::InvArgsException::what() const throw() {
	return "Invalid arguments! Check your input and try again!";
}