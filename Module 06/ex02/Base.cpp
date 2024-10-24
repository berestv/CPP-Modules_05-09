#include "Base.hpp"

Base::~Base() {}

// FUNCTIONS

Base *Base::generate() {
	srand(static_cast<unsigned int>(time(0)) ^ getpid());
	int rnd = rand() % 3;

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

}

void Base::identify(Base &p) {

}