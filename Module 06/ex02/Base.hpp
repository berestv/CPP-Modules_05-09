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

#endif //BASE_HPP
