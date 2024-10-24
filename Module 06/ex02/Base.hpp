#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
// typeinfo
// HA! Gotcha.

class Base {
public:
	virtual ~Base();

	Base * generate(void);
	void identify(Base* p);
	void identify(Base& p);
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {

};

#endif //BASE_HPP
