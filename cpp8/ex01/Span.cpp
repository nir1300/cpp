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

int Span::shortestSpan(void) const
{
    int shortest_span = -1;
    if (_vec.size() <= 1)
        throw NoSpanFoundException();
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    for (long unsigned int i = 1; i < tmp.size(); i++)
    {
        if (tmp[i] - tmp[i - 1] < shortest_span || shortest_span < 0)
            shortest_span = tmp[i] - tmp[i - 1];
    }
    return shortest_span;
}

int Span::longestSpan(void) const
{
    if (_vec.size() <= 1)
        throw NoSpanFoundException();
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    int vMin = *tmp.begin();
    int vMax = tmp.back();
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
        int randoNum = std::rand();
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


