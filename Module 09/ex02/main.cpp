#include "PmergeMe.hpp"

int main (int argc, char* argv[]) {
	if (argc >= 2) {
		try {
			std::stringstream ss;
			for (int i = 1; i < argc; ++i)
				ss << argv[i] << " ";
			PmergeMe pm(ss);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error" << std::endl;
	return 0;
}