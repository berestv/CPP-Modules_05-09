#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class easyfind {
	class NotFoundE : public std::exception {
	public:
		virtual const char* what() const throw();
	};
};

#include "easyfind.tpp"

#endif //EASYFIND_HPP
