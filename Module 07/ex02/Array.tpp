#ifndef ARRAY_TPP
#define ARRAY_TPP

template <class T>
Array<T>::Array() : sz(0)
{
	elm = new T[sz];
}

#endif //ARRAY_TPP