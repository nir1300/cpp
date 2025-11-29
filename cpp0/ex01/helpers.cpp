#include "PhoneBook.hpp"

bool    str_isalpha(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isalpha(str[i]))
            return false;
    }
    return true;
}

bool    str_isdigit(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}