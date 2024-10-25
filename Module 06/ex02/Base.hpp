#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <unistd.h>
#include <cstdlib>
// typeinfo
// HA! Gotcha.

class Base {
public:
	virtual ~Base();

	static Base * generate(void);
	static void identify(Base* p);
	static void identify(Base& p);
};

class A : public Base { };
class B : public Base { };
class C : public Base { };

#endif //BASE_HPP
