#include "Span.hpp"

Span::Span(unsigned int n) {
	if (n >= 0 && n <= 2147483647)
	{
		max = n;
		//stash = std::vector<int>(5);
		stash.reserve(n);
	}
	else
		throw InvArgsException();
}

Span::Span(const Span &cpy) {
	this->max = cpy.max;
	this->stash = cpy.stash;
}

Span &Span::operator=(const Span &cpy) {
	if (this != &cpy)
	{
		this->max = cpy.max;
		this->stash = cpy.stash;
	}
	return *this;
}

Span::~Span() {
	
}

void Span::addNumber(int n) {
	if (stash.size() >= max)
		throw FullVecException();
	else
		stash.push_back(n);
}

unsigned int Span::shortestSpan() {
	int size = stash.size();
	if (size < 2)
		throw NotEnoughNumException();

	std::vector<int> temp = stash;
	std::sort(temp.begin(), temp.end());
	int shSp = stash[1] - stash[0];
	for (int i = 1; i < size; i++) {
		if (shSp > (stash[i + 1] - stash[i]))
			shSp = stash[i + 1] - stash[i];
	}
	return shSp;
}

unsigned int Span::longestSpan() {
	if (stash.size() < 2)
		throw NotEnoughNumException();

	return (std::max(stash.begin(), stash.end()) - std::min(stash.begin(), stash.end()));
}

const char *Span::InvArgsException::what() const throw() {
	return "Invalid arguments! Check your input and try again.";
}

const char *Span::FullVecException::what() const throw() {
	return "Cannot add more elements: Span is full.";
}

const char *Span::NotEnoughNumException::what() const throw() {
	return "Cannot complete operation: at least two numbers in Span are required.";
}
