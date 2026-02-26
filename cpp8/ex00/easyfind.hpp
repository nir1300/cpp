#pragma once

#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class ElementNotFoundException: public std::exception {
    public:
        virtual const char* what() const throw();
};

const char *ElementNotFoundException::what() const throw()
{
    return ("Element not found");
}

template <class T> void easyfind(T v, int i)
{
    std::vector<int>::iterator it = find(v.begin(), v.end(), i);
    if (it != v.end())
        std::cout << *it << std::endl;
    else
        throw ElementNotFoundException();
}


#endif