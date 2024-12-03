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

	return 0;
}
