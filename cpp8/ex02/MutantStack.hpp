#pragma once

#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>
#include <ctime>

template <class T>
class MutantStack : public std::stack<T> {
    private:

    public:
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack& other);
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin();
        iterator end();
};

#include "MutantStack.tpp"

#endif