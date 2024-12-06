#include "easyfind.hpp"

int main() {
	try {
		int container[7] = { 21, 42, 35, 1, 29, 55, 3 };
		easyFind(container, 42);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
