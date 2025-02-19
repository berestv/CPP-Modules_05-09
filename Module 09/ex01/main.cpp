#include "RPN.hpp"

int main (int argc, char* argv[]) {
	if (argc == 2)
	{
		try {
			RPN rpn(argv[1]);
		} catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	else
		std::cerr << "Error: Wrong number of arguments" << std::endl;
	return 0;
}