#include "easyfind.hpp"

const char *ElementNotFoundException::what() const throw()
{
    return ("Element not found");
}

template <typename T> 
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end())
        return it;
    else
        throw ElementNotFoundException();
}