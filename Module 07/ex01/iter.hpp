#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T& arr, int len, T& func(T lmt)) {
	for (int i = 0; i <= len; ++i)
		func(arr[i]);
}

#endif //ITER_HPP
