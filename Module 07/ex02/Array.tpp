// TEMPLATE
#include "Array.hpp"

template <class T>
Array<T>::Array() : sz(0) {
	elm = new T[sz];
}

template <class T>
Array<T>::Array(unsigned int num) {
	elm = new int();
}

template <class T> Array<T>::~Array()
{
	if (elm)
		delete [] elm;
}
