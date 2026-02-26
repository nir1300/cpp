#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n), _currentSize(n) {}

Span::~Span() {}

Span::Span(const Span &other) : _maxSize(other._maxSize), _currentSize(other._currentSize)
{
    _vec = other._vec;
}

Span &Span::operator=(const Span& other)
{
    if (this == &other)
        return *this;
    _maxSize = other._maxSize;
    _currentSize = other._currentSize;
    _vec = other._vec;
    return *this;
}

int Span::shortestSpan(void)
{  
    return 0;
}

int Span::longestSpan(void)
{
    if (_vec.size() <= 1)
        throw NoSpanFoundException();
    sort(_vec.begin(), _vec.end());
    int vMin = *_vec.begin();
    int vMax = *_vec.end();
    std::cout << "min/nax: " << vMin << " " << vMax << std::endl;
    return (vMax - vMin);
    return 0;
}

void Span::addNumber(int n)
{
    _vec.push_back(n);
}

void Span::addNumbers(int n)
{
    (void)n;
}

const char *Span::NoSpanFoundException::what() const throw()
{
    return ("Element not found");
}


