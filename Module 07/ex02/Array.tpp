// TEMPLATE
#include "Array.hpp" // REMOVE

template <typename T>
Array<T>::Array() : sz(0) {
	elm = new T[sz];
}

template <typename T>
Array<T>::Array(unsigned int num) : sz(num) {
	elm = new T[num];
	for (int i = 0; i < num; i++) {
		elm[i] = new T();
	}
}

template<class T>
Array<T>::Array(const Array<T> &cpy) {
	sz = cpy.sz;
	elm = new T[sz];
	for (int i = 0; i < sz; i++)
		elm[i] = cpy.elm[i];
}

template<class T>
Array<T> &Array<T>::operator=(const Array<T> &cpy) {
	if (this != cpy)
	{
		sz = cpy.sz;
		elm = new T[sz];
		for (int i = 0; i < sz; i++)
			elm[i] = cpy.elm[i];
	}
	return *this;
}

template <class T>
Array<T>::~Array()
{
	if (elm)
		delete[] elm;
}
