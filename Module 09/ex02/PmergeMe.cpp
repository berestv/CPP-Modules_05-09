#include "PmergeMe.hpp"

PmergeMe::PmergeMe(const std::string& input) {
	if (input.empty() || input.find_first_not_of(" 0123456789") != std::string::npos)
		throw InvalidInputException();

	std::stringstream ss(input);
	std::string n;
	while (ss >> n)
		num.push_back(atoi(n.c_str()));
	printVec('b');
}

PmergeMe::PmergeMe(const PmergeMe &cpy) {
	this->num = cpy.num;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy) {
	if (this != &cpy)
		this->num = cpy.num;
	return *this;
}

PmergeMe::~PmergeMe() {

}

// FUNCTIONS
void PmergeMe::printVec(const char c) const {
	if (c == 'b')
		std::cout << "Before: ";
	else if (c == 'a')
		std::cout << "After:  ";
	for (size_t i = 0; i < num.size(); ++i) {
		std::cout << num[i] << " ";
	}
	std::cout << std::endl;
}


const char *PmergeMe::InvalidInputException::what() const throw() {
	return "Error: Invalid input. Please input only positive integers separated by spaces.";
}

