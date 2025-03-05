#include "PmergeMe.hpp"

int main (int argc, char* argv[]) {
	if (argc == 2) {
		try {
			PmergeMe pm(argv[1]);
		} catch (std::exception& e) {
			std::cerr << e.what() << std::endl;
		}

	}
	else
		std::cerr << "Error" << std::endl;
	return 0;
}