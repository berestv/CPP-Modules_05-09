// easyfind.tpp
#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template<typename T>
void easyFind(T& cont, int n){
	T pos = std::find(cont.begin(), cont.end(), n);
	if (pos == cont.end())
		throw easyFind::NotFoundException();
	std::cout << "Found " << n << " at " << pos << std::endl;
}

const char *easyFind::NotFoundException::what() const throw() {
	return "";
}

#endif //EASYFIND_TPP
