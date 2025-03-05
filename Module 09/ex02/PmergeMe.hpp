#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "iostream"
#include "vector"
#include <sstream>
#include "stdlib.h"

class PmergeMe {
private:
	std::vector<int> num;

public:
	PmergeMe(const std::string& input);
	PmergeMe(const PmergeMe &cpy);
	PmergeMe &operator=(const PmergeMe &cpy);
	~PmergeMe();

	void printVec(char c) const;

	class InvalidInputException : public std::exception {
		virtual const char* what() const throw();
	};
};

#endif //PMERGEME_HPP
