#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <list>
#include <stack>

template<typename T> class MutantStack : public std::stack<T> {
public:
	MutantStack();
	MutantStack(const MutantStack& cpy);
	MutantStack &operator=(const MutantStack& cpy);
	~MutantStack();

	typedef typename std::stack<T>::container_type::iterator iterator;
	iterator begin();
	iterator end();
};

template <typename T>
MutantStack<T>::MutantStack() {

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &cpy) {
	*this = cpy;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &cpy) {
	if (this != &cpy)
		std::stack<T>::operator=(&cpy);
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {

}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return std::stack<T>::c.end();
}

#endif //MUTANTSTACK_HPP
