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
        exit(1);// return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i]; // leak for invalid inputs??
        for (size_t j = 0; j < arg.size(); j++)
        {
            if (arg[j] != ' ' && !std::isdigit(arg[j]))
            {
                std::cerr << "Error" << std::endl;
                exit(1);// return 1;
            }
        }
    }
    // return 0;
}

void printBefore(int argc, char **argv)
{
    std::cout << "Before: ";
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i];
        if (i + 1 < argc)
            std::cout << " ";
    }
    std::cout << std::endl;
}

void printTime()
{

}

// void	PmergeMe::printTime( void )
// {
//     clock_t start = clock();
//     char buffer[80];
//     std::time_t raw;
//     std::time(&raw);
//     std::tm* local = std::localtime(&raw);
//     std::strftime(buffer, 80, "%Y%m%d_%H%M%S", local);
//     std::cout << "[" << buffer << "] ";
// }


PmergeMe::PmergeMe(int argc, char **argv) : argcStored(argc), argvStored(argv) 
{
    size = argc - 1;
    comparisons = 0;
}

// void putInContainer(Container& c, int argc, char **argv)
// {
//     for (int i = 1; i < argc; i++)
//     {
//         std::string str = argv[i];
//         for (size_t j = 0; j < str.length(); j++)
//         {
//             int res = 0;
//             while (str[j] && str[j] == ' ')
//                 j++;
//             if (!str[j] || !isdigit(str[j]))
//                 continue;
//             while (str[j] && isdigit(str[j]))
//             {
//                 res = (res * 10) + (str[j] - '0');
//                 j++;
//             }
//             c.push_back(res);
//         }
//     }
// }

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
    this->vec = other.vec;
    this->deq = other.deq;
    this->size = other.size;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& other)
{
    if (this == &other)
        return *this;
    this->vec = other.vec;
    this->deq = other.deq;
    this->size = other.size;
    return *this;
}



