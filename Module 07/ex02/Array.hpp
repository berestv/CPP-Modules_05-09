#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T> class Array {
private:
	T *elm;
	unsigned int sz;
public:
	Array();
	Array(unsigned int num);
	Array(const Array& cpy);
	Array &operator=(const Array& cpy);
	~Array();

	unsigned int size();
};

#include "Array.tpp"

#endif //ARRAY_HPP
