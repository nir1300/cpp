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

PmergeMe::PmergeMe(int argc, char **argv) : argcStored(argc), argvStored(argv) 
{
    size = argc - 1;
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

void PmergeMe::sort()
{
    // vector
    clock_t start = clock();
    std::vector<int> vec;
    putInContainer(vec, argcStored, argvStored);
    if (size == 1 || isSorted(vec))
    {
        std::cout << "Already sorted" << std::endl;
        return;
    }
    std::vector<int> before = vec;
    std::vector<std::pair<int, int> > vecPairs;
    mergeInsertion(vec, vecPairs);
    clock_t end = clock();
    double elapsedVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    // deque
    start = clock();
    std::deque<int> deq;
    putInContainer(deq, argcStored, argvStored);
    if (size == 1 || isSorted(deq)) // technically redundant but want to mimic vector logic to not get difference in execution time from error handling only 1 container
    {
        std::cout << "Already sorted" << std::endl;
        return;
    }
    std::deque<int> beforeDeq = deq; // technically redundant again
    std::deque<std::pair<int, int> > deqPairs;
    mergeInsertion(deq, deqPairs);
    end = clock();
    double elapsedDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    // print
    printContainerContents(before, "Before: ");
    printContainerContents(vec, "After:  ");

    // std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << size << " elements with std::deque:  " << elapsedDeq << " us" << std::endl;
    std::cout << "Time to process a range of " << size << " elements with std::vector: " << elapsedVec << " us" << std::endl;

    if (!isSorted(deq) || !isSorted(vec))
        std::cout << "ERROR - Sorted incorrectly!" << std::endl;
    else
        std::cout << "SUCCESS - Sorted correctly!" << std::endl;
}