// easyfind.tpp
#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template<typename T>
void easyFind(T cont, int n){
	T pos = std::find(cont.begin(), cont.end(), n);
	if (pos == cont.end())
		throw easyFind::NotFoundException();
	std::cout << "Found " << n << " at " << pos << std::endl;
}

#endif //EASYFIND_TPP
