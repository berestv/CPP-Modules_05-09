#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>
#include <stdlib.h>
#include <iomanip>

class PmergeMe {
private:
	std::vector<int> num;

public:
	PmergeMe(std::stringstream& ss);
	PmergeMe(const PmergeMe &cpy);
	PmergeMe &operator=(const PmergeMe &cpy);
	~PmergeMe();

	void printVec(char c) const;
	void sortVec();

	class InvalidInputException : public std::exception {
		virtual const char* what() const throw();
	};

	class InvalidSizeExcepiton : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif //PMERGEME_HPP
