#pragma once

#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span {
    private:
        unsigned int _maxSize;
        unsigned int _currentSize;
        std::vector<int> _vec;
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span &other);
        Span &operator=(const Span& other);

        int shortestSpan(void);
        int longestSpan(void);
        void addNumber(int n);
        void addNumbers(int n);
        class NoSpanFoundException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
};


#endif