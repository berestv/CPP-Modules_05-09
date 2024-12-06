// easyfind.tpp
#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"

template<typename T>
T easyFind(T& cont, int n){
	T pos = std::find(cont.begin(), cont.end(), n);
	if (pos == cont.end())
		throw easyFind::NotFoundException();
	return pos;
}

#endif //EASYFIND_TPP
