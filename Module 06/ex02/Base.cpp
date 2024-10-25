#include "Base.hpp"

Base::~Base() {}

// FUNCTIONS

Base *Base::generate() {
	static int last;
	srand(static_cast<unsigned int>(time(0)) ^ getpid());

	int rnd = rand() % 3;
	while (last == rnd)
		rnd = rand() % 3;
	last = rnd;

	switch (rnd) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return NULL;
	}
}

void Base::identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Doesn't match A, B or C" << std::endl;
	delete p;
}

void Base::identify(Base &p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return (void)delete &p;
	}
	catch (std::exception& e) {	}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return (void)delete &p;
	}
	catch (std::exception& e) { }

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return (void)delete &p;
	}
	catch (std::exception& e) {	}
}