#pragma once

#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>
#include <exception>

template <class T>
class Array {
    private:
        T* array;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        ~Array();
        Array &operator=(const Array &other);
        T &operator[](unsigned int i);
        const T &operator[](unsigned int i) const;
        unsigned int size() const;

        class OutOfBoundsException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

#include "Array.tpp"

#endif