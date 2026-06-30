#include "MutantStack.hpp"

MutantStack::MutantStack(unsigned int n) {}

MutantStack::~MutantStack() {}

MutantStack::MutantStack(const MutantStack &other)
{
}

MutantStack &MutantStack::operator=(const MutantStack& other)
{
    if (this == &other)
        return *this;

    return *this;
}