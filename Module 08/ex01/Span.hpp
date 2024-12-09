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
};

#endif //SPAN_HPP
