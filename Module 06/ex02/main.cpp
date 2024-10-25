#include "Base.hpp"

int main() {
	Base& base = *Base::generate();
	Base* base2 = Base::generate();


	Base::identify(&base);
	Base::identify(*base2);
	Base::identify(Base::generate());
	Base::identify(*Base::generate());
}