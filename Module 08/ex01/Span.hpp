#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span {
private:
	unsigned int max;
	std::vector<int> stash;

public:
	Span(unsigned int n);
	Span(const Span& cpy);
	Span &operator=(const Span& cpy);
	~Span();

	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();
	void addMany(unsigned int n);

	class InvArgsException : public std::exception {
		virtual const char* what() const throw();
	};
	class FullVecException : public std::exception {
		virtual const char* what() const throw();
	};
	class NotEnoughNumException : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif //SPAN_HPP
