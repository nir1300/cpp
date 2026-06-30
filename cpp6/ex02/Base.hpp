#pragma once

#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <iostream>
#include <ctime>
#include <exception>
#include <cstdlib>

class Base {
    // classes dont need to be OCF
    // polymoprhism requires class to be polymorphic (this needs at least 1 virtual function)
    // ensures child class is cleaned up
    public:
    virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif