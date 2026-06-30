#pragma once

#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>


class MutantStack : public std::stack<T> {
    private:

    public:
        MutantStack(unsigned int n);
        ~MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack &operator=(const MutantStack& other);
};


#endif