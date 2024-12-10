#include "Span.hpp"

Span::Span(unsigned int n) {
	if (n > 2147483647)
		throw InvArgsException();
	max = n;
	stash.reserve(n);
	//stash = std::vector<int>(5);
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
	int shSp = temp[1] - temp[0];
	for (int i = 1; i < size - 1; i++) {
		if (shSp > (temp[i + 1] - temp[i]))
			shSp = temp[i + 1] - temp[i];
	}
	return shSp;
}

unsigned int Span::longestSpan() {
	if (stash.size() < 2)
		throw NotEnoughNumException();

	return (*std::max_element(stash.begin(), stash.end()) - *std::min_element(stash.begin(), stash.end()));
}

void Span::addMany(unsigned int n) {

	if (n > 2147483647 || n > stash.size() - 1)
		throw InvArgsException();

	for (unsigned int i = 3; i <= n * 3; i += 3)
		addNumber(i);
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
