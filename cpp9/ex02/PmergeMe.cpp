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
        std::string arg = argv[i]; // leak for invalid inputs??
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

void printTime()
{

}

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

std::vector<int> PmergeMe::generateJacob()
{
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    for (size_t i = 1; i < size; i++)
    {
        size_t tmp = jacob[i] + (2*jacob[i-1]);
        // std::cout << "tmp: " << tmp << std::endl;
        if (tmp <= size)
            jacob.push_back(tmp);
        else if (tmp > size)
            break;
    }
    std::vector<int> gaps;
    gaps.push_back(jacob[0]);
    for (size_t i = 1; i < jacob.size(); i++)
    {
        for (size_t j = 0; j < gaps.size(); j++)
        {
            // if (gaps.size() == size/3)
            //     break;
            if (gaps[j] == jacob[i] || gaps.size() >= size/2)
                break;
            else if (j == gaps.size() - 1 && gaps[j] != jacob[i])
            {
                gaps.push_back(jacob[i]);
                if (jacob[i] != jacob[i-1]-1)
                {
                    int tmp = jacob[i]-1;
                    while (tmp != jacob[i-1])
                    {
                        gaps.push_back(tmp--);
                    }
                }
            }
        }
    }
    // printJacob(gaps);
    return gaps;

}

void    PmergeMe::printJacob(std::vector<int> jacob)
{
    std::cout << "JACOB: ";
    for (size_t i = 0; i < jacob.size(); i++)
        std::cout << jacob[i] << " ";
    std::cout << std::endl;
}

