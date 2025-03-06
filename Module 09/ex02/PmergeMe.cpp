#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::stringstream& ss) {
	std::string n;

	while (ss >> n) {
		if (n.empty() || n.find_first_not_of(" 0123456789") != std::string::npos)
			throw InvalidInputException();
		num.push_back(atoi(n.c_str()));
	}
	if (num.size() <= 1)
		throw InvalidSizeExcepiton();

	printVec('b');
	sortVec();
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

void PmergeMe::sortVec() {
	clock_t start = clock();

	int i = 0;
	while (i < 12312314)
		i++;

	clock_t finish = clock();
	double elapsed = (double(finish - start) / CLOCKS_PER_SEC);
	std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << num.size()
	<< " elements with std::vector : " << elapsed << " μs" << std::endl;
}

// EXCEPTIONS

const char *PmergeMe::InvalidInputException::what() const throw() {
	return "Error: Invalid input. Please input only positive integers separated by spaces.";
}

const char *PmergeMe::InvalidSizeExcepiton::what() const throw() {
	return "Error: Invalid vector size.";
}


