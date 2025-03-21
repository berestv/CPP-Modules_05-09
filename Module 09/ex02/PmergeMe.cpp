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
	std::deque<int> deq(num.begin(), num.end());

	printVec('b');
	clock_t start = clock();
	sortVec(num);
	clock_t finish = clock();
	printVec('a');
	double elapsed = (static_cast<double>(finish - start) / CLOCKS_PER_SEC) * 1000;
	std::cout << "Time to process a range of " << num.size() << " elements with std::vector : "
	<< std::fixed << std::setprecision(3) <<  elapsed << " ms" << std::endl;

	start = clock();
	sortDeq(deq);
	finish = clock();

	elapsed = (static_cast<double>(finish - start) / CLOCKS_PER_SEC) * 1000;
	std::cout << "Time to process a range of " << num.size() << " elements with std::deque  : "
	<<  elapsed << " ms" << std::endl;
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

// ----- FUNCTIONS ------
// VECTOR OPERATIONS

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

void makePairs(std::vector<int> &vec, std::vector<int> &large, std::vector<int> &small, int& lftOut) {
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
}

void PmergeMe::sortVec(std::vector<int> &vec) {
	if (vec.size() <= 1)
		return ;

	int lftOut;
	std::vector<int> large;
	std::vector<int> small;

	makePairs(vec, large, small, lftOut);

	if (!isVecSorted(large))
		sortVec(large);

	vec.clear();
	vec.insert(vec.begin(), large.begin(), large.end());

	for (size_t i = 0; i < small.size(); ++i)
	{
		if (i == 0)
			vec.insert(vec.begin(), small.front());
		else
			binaryInsert(vec, small[i]);
	}

	if (lftOut != -1)
		binaryInsert(vec, lftOut);
}

bool PmergeMe::isVecSorted(std::vector<int> &vec) {
	if (vec.empty())
		throw InvalidSizeExcepiton();
	for (size_t i = 0; i + 1 < vec.size(); ++i)
		if (vec[i] > vec[i + 1])
			return false;
	return true;
}

// DEQUE OPERATIONS

void binaryInsertDeq(std::deque<int>& sorted, int value) {
	std::deque<int>::iterator it = std::lower_bound(sorted.begin(), sorted.end(), value);
	sorted.insert(it, value);
}

void makePairsDeq(const std::deque<int>& deq, std::deque<int> &large, std::deque<int> &small, int& lftOut) {
	lftOut = -1;

	for (size_t i = 0; i + 1 < deq.size(); i += 2) {
		if (deq[i] > deq[i + 1]) {
			large.push_back(deq[i]);
			small.push_back(deq[i + 1]);
		} else {
			large.push_back(deq[i + 1]);
			small.push_back(deq[i]);
		}
	}

	if (deq.size() % 2 != 0) {
		lftOut = deq.back();
	}
}

void PmergeMe::sortDeq(std::deque<int> &deq) {
	if (deq.size() <= 1)
		return ;

	int lftOut;
	std::deque<int> large;
	std::deque<int> small;

	makePairsDeq(deq, large, small, lftOut);

	if (large.size() < deq.size())
		sortDeq(large);

	deq.clear();
	deq.insert(deq.begin(), large.begin(), large.end());

	for (size_t i = 0; i < small.size(); ++i)
		binaryInsertDeq(deq, small[i]);

	if (lftOut != -1)
		binaryInsertDeq(deq, lftOut);
}

// EXCEPTIONS

const char *PmergeMe::InvalidInputException::what() const throw() {
	return "Error: Invalid input. Please input only positive integers separated by spaces.";
}

const char *PmergeMe::InvalidSizeExcepiton::what() const throw() {
	return "Error: Invalid vector size.";
}


