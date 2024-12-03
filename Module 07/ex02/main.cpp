#include "Array.hpp"

int main() {
	try {
		Array<int> arr(10);
		std::cout << "Initial values:" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << std::endl;
			arr[i] = i;
		}
		std::cout << "After increment:" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Array<int> arr(10);
		std::cout << "O.O.B. test:" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << std::endl;
			arr[i] = i;
		}
		arr[11] = 1;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Array<int> arr(10);
		std::cout << "Array 1 values:" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
		{
			std::cout << arr[i] << std::endl;
			arr[i] = i;
		}
		Array<int> arr2 = arr;
		arr2[3] = 100;
		std::cout << "Array 2 values after [3] = 100:" << std::endl;
		for (unsigned int i = 0; i < arr2.size(); i++)
			std::cout << arr2[i] << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
