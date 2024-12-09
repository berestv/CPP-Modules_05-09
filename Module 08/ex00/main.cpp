#include "easyfind.hpp"

int main() {
	try {
		std::cout << "Vector Test:" << std::endl;
		std::vector<int> container;
		container.push_back(21);
		container.push_back(42);
		container.push_back(35);
		container.push_back(1);
		container.push_back(29);
		container.push_back(55);
		container.push_back(3);
		easyFind(container, 42);
		easyFind(container, 43);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try {
		std::cout << "List Test:" << std::endl;
		std::list<int> container;
		container.push_back(33);
		container.push_back(526);
		container.push_back(99);
		container.push_back(7);
		container.push_back(123);
		container.push_back(82);
		container.push_back(54);
		easyFind(container, 7);
		easyFind(container, 526);
		easyFind(container, 500);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}
