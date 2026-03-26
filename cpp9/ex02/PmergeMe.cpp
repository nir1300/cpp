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
    std::cout << "Before: ";
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

PmergeMe::PmergeMe(std::vector<int> vec, std::deque<int> deq) : vec(vec), deq(deq) 
{
    size = vec.size();
}

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