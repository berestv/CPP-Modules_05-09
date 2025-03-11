#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <utility>

class PmergeMe {
private:
	std::vector<int> num;

public:
	PmergeMe(std::stringstream& ss);
	PmergeMe(const PmergeMe &cpy);
	PmergeMe &operator=(const PmergeMe &cpy);
	~PmergeMe();

	void printVec(char c) const;
	void sortVec(std::vector<int> &vec);
	bool isVecSorted(std::vector<int> &vec);

	class InvalidInputException : public std::exception {
		virtual const char* what() const throw();
	};

	class InvalidSizeExcepiton : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif //PMERGEME_HPP
