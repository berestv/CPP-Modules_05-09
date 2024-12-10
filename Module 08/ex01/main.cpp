#include "Span.hpp"

int main() {
	std::cout << "| Testing negative parameter:" << std::endl;
	try {
		Span negSpan(-10000);
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	std::cout << "| Testing empty span:" << std::endl;
	try {
		Span span(5);
		span.addNumber(1);
		span.shortestSpan();
		span.longestSpan();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	std::cout << "| Testing normal:" << std::endl;
	try {
		Span span(10000);

		for (int i = 0; i < 10000; ++i) {

		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
