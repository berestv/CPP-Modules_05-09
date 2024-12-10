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

	std::cout << "| Testing full span:" << std::endl;
	try {
		Span span(1);
		span.addNumber(1);
		span.addNumber(2);
		span.shortestSpan();
		span.longestSpan();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << "| Testing normal:" << std::endl;
	try {
		Span span(10000);

		for (int i = 10; i < 50000; i+= 5)
			span.addNumber(i);
		span.addNumber(9);
		span.addNumber(100000);
		std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "Longest  span: " << span.longestSpan() << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
