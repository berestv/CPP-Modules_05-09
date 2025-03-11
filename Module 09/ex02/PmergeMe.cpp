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

/*void binaryInsert(std::vector<int>& vec, int val) {
	std::vector<int>::iterator it = std::lower_bound(vec.begin(), vec.end(), val);
	vec.insert(it, val);
}*/

void PmergeMe::sortVec(std::vector<int> &vec) {
	clock_t start = clock();

	std::vector<int> l, r;

	for (size_t i = 0; i + 1 < vec.size() ; ++i) {
		if (vec[i] > vec[i + 1])
		{
			l.push_back(vec[i]);
			r.push_back(vec[i + 1]);
		}
		else
		{
			l.push_back(vec[i + 1]);
			r.push_back(vec[i]);
		}
	}

	if (vec.size() % 2 != 0)
		l.push_back(vec.back());

	if (!isVecSorted(vec))
		sortVec(l);


	clock_t finish = clock();
	double elapsed = (double(finish - start) / CLOCKS_PER_SEC);
	std::cout << std::fixed << std::setprecision(5) << "Time to process a range of " << num.size()
	<< " elements with std::vector : " << elapsed << " μs" << std::endl;
}

bool PmergeMe::isVecSorted(std::vector<int> &vec) {
	for (int i = 0; i + 1 < vec.size(); ++i)
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


