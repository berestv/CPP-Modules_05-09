#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class easyfind {
class NotFOundExcp : public std::exception {
public:
	virtual const char* what() const throw();
};
};

#include "easyfind.tpp"

#endif //EASYFIND_HPP
