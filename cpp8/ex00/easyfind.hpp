#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <exception>
#include <list>


class ElementNotFoundException: public std::exception {
    public:
        virtual const char* what() const throw();
};

#include "easyfind.tpp"


#endif