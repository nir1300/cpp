#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <exception>


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

        int shortestSpan(void) const;
        int longestSpan(void) const;
        void addNumber(int n);
        void addNumbers(int n);
        class NoSpanFoundException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class ClassFullException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
};


#endif