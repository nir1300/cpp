#include "Span.hpp"

Span::Span(unsigned int n) : _maxSize(n), _currentSize(0) {}

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
    int shortest_span = -1;
    if (_vec.size() <= 1)
        throw NoSpanFoundException();
    sort(_vec.begin(), _vec.end());
    for (long unsigned int i = 1; i < _vec.size(); i++)
    {
        if (_vec[i] - _vec[i - 1] < shortest_span || shortest_span < 0)
            shortest_span = _vec[i] - _vec[i - 1];
    }
    return shortest_span;
}

int Span::longestSpan(void)
{
    if (_vec.size() <= 1)
        throw NoSpanFoundException();
    sort(_vec.begin(), _vec.end());
    int vMin = *_vec.begin();
    int vMax = _vec.back();
    return (vMax - vMin);
}

void Span::addNumber(int n)
{
    if (_currentSize == _maxSize)
        throw ClassFullException();
    _vec.push_back(n);
    _currentSize++;
}

void Span::addNumbers(int n)
{
    std::srand(std::time(NULL));
    for (int i = 0; i < n; i++)
    {
        int randoNum = std::rand() % RAND_MAX;
        addNumber(randoNum);
    }
}

const char *Span::NoSpanFoundException::what() const throw()
{
    return ("Span not found (not enough elements)");
}

const char *Span::ClassFullException::what() const throw()
{
    return ("Maximum integers stored already");
}


