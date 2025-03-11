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
	sortVec(num);
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

void binaryInsert(std::vector<int>& sorted, int value) {
	std::vector<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}

std::pair<std::vector<int>,std::vector<int> > makePairs(const std::vector<int>& vec, int& lftOut) {
	;
	std::vector<int> large;
	std::vector<int> small;
	lftOut = -1;

	for (size_t i = 0; i + 1 < vec.size(); i += 2) {
		if (vec[i] > vec[i + 1]) {
			large.push_back(vec[i]);
			small.push_back(vec[i + 1]);
		} else {
			large.push_back(vec[i + 1]);
			small.push_back(vec[i]);
		}
	}

	if (vec.size() % 2 != 0) {
		lftOut = vec.back();
	}
	std::pair<std::vector<int>,std::vector<int> > pairs(large, small);
	return pairs;
}

void PmergeMe::sortVec(std::vector<int> &vec) {
	clock_t start = clock();

	if (vec.size() <= 1)
		return ;

	int lftOut;

	std::pair<std::vector<int>,std::vector<int> > pairs = makePairs(vec, lftOut);
	std::vector<int>& large(pairs.first);
	std::vector<int>& small(pairs.second);

	if (large.size() < num.size())
		sortVec(large);
	else
		return ;

	num.erase(num.begin(), num.end());
	num.insert(num.begin(), large.begin(), large.end());

	for (size_t i = 0; i < small.size(); ++i) {
		binaryInsert(num, small[i]);
	}

	if (lftOut != -1)
		binaryInsert(num, lftOut);

	clock_t finish = clock();
	double elapsed = (double(finish - start) / CLOCKS_PER_SEC); //* 1000000;
	printVec('a');
	std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << num.size()
	<< " elements with std::vector : " << elapsed << " μs" << std::endl;
}

bool PmergeMe::isVecSorted(std::vector<int> &vec) {
	if (vec.empty())
		throw InvalidSizeExcepiton();
	for (size_t i = 0; i + 1 <= vec.size(); ++i)
		if (vec[i] > vec[i + 1])
			return false;
	return true;
}

// EXCEPTIONS

const char *PmergeMe::InvalidInputException::what() const throw() {
	return "Error: Invalid input. Please input only positive integers separated by spaces.";
}

const char *PmergeMe::InvalidSizeExcepiton::what() const throw() {
	return "Error: Invalid vector size.";
}


