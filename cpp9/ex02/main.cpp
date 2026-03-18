#include "PmergeMe.hpp"
#include <stdlib.h>
#include <deque>
#include <vector>
#include <utility>

// input -> container -> algorithm -> sorted container
// insert via iterator: insert(iterator, value);

// STEPS IN ALGORITHM
// 1. create pairs
// 2. sort inside each pair
// 3. build main chain: take larger elements and recursively sort them
// 4. build pending chain
// 5. insert first pending element at front, insert the rest using jacobsthal order, find position with binary search


template <typename Container>
void printPairs(Container& c)
{
    typename Container::iterator it = c.begin();
    while (it != c.end())
    {
        std::cout << "[" << it.first << ", " << it.second << "], ";
        it++;
    }
    std::cout << std::endl;
}

template <typename Container>
void mergeInsertion(Container& c)
{
    // createPairs();
    // Container<std::pair<int, int>> pairs;
    typename Container::iterator it = c.begin();
    for (size_t i = 0; i < c.size() / 2; i++)
        pairs.insert(std::make_pair(*it++, *it++, NULL));
    printPairs(c);

    // sortPairs();
}

int main(int argc, char **argv)
{
    errorHandling(argc, argv);
    printBefore(argc, argv);

    std::vector<int> vec;
    std::deque<int> deq;
    putInContainer(vec, argc, argv);
    putInContainer(deq, argc, argv);
    printContainerContents(vec, "Vector: ");
    printContainerContents(deq, "Deque: ");
    mergeInsertion(vec);
    // printOutput();
    // printTime();
}