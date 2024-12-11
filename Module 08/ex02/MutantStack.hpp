#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<class T> class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(const MutantStack& cpy);
	MutantStack &operator=(const MutantStack& cpy);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
};

#include "MutantStack.tpp"

#endif //MUTANTSTACK_HPP
