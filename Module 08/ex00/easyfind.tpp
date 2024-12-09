// easyfind.tpp
#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template<typename T>
void easyFind(T& cont, int n){
	typename T::iterator pos = std::find(cont.begin(), cont.end(), n);
	if (pos == cont.end())
		throw easyFind::NotFoundException();
	std::cout << "Found " << n << " at " << std::distance(cont.begin(), pos) << std::endl;
}

const char *easyFind::NotFoundException::what() const throw() {
	return "Could not find value.";
}

#endif //EASYFIND_TPP
