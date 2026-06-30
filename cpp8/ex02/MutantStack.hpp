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
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        const_iterator begin() const;
        const_iterator end() const;
        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
        reverse_iterator rbegin();
        reverse_iterator rend();
        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
        const_reverse_iterator rbegin() const;
        const_reverse_iterator rend() const;
};

// const iterator: read only access to container elements

#include "MutantStack.tpp"

#endif