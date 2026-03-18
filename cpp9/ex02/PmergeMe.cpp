#include "PmergeMe.hpp"
#include <stdlib.h>
#include <deque>
#include <vector>
// containers: use vector and deque

void errorHandling(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Error: missing arguments" << std::endl;
        exit(1);
    }
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];
        for (size_t j = 0; j < arg.size(); j++)
        {
            if (arg[j] != ' ' && !std::isdigit(arg[j]))
            {
                std::cerr << "Error" << std::endl;
                exit(1);
            }
        }
    }
}

void printBefore(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i];
        if (i + 1 < argc)
            std::cout << " ";
    }
    std::cout << std::endl;
}

// void printTime()
// {
//     std::cout << "Time to process a range of " << n << "elements with std::vector: " << time << " us" << std::endl;
//     std::cout << "Time to process a range of " << n << "elements with std::deque: " << time << " us" << std::endl;
// }

template <typename Container>
void putInContainer(Container& c, int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        for (size_t j = 0; j < str.length(); j++)
        {
            int res = 0;
            while (str[j] == ' ')
                continue;
            while (str[j] && isdigit(str[j]))
            {
                res = (res * 10) + (str[j] - '0');
                j++;
            }
            c.push_back(res);
        }
    }
}

template <typename Container>
void printContainerContents(Container& c, std::string str)
{
    std::cout << str;
    typename Container::iterator it = c.begin();
    while (it != c.end())
        std::cout << *it++ << " ";
    std::cout << std::endl;
}
