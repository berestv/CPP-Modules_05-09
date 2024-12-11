// Template file
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &cpy) {

}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &cpy) {

}

template <typename T>
MutantStack<T>::~MutantStack() {

}

template <typename T>
iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template <typename T>
iterator MutantStack<T>::end() {
	return std::stack<T>::c.end();
}