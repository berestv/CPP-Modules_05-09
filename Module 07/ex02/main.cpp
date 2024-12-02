#include "Array.hpp"

int main() {
	Array<int> arr(10);

	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << arr[i] << std::endl;

	return 0;
}
