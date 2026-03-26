#include "PmergeMe.hpp"
#include <algorithm>

// input -> container -> algorithm -> sorted container
// insert via iterator: insert(iterator, value);

// STEPS IN ALGORITHM
// 1. create pairs
// 2. sort inside each pair
// 3. build main chain: take larger elements and recursively sort them
// 4. build pending chain
// 5. insert first pending element at front, insert the rest using jacobsthal order, find position with binary search


// template <typename Container>
// void printPairs(Container& c)
// {
//     typename Container::iterator it = c.begin();
//     while (it != c.end())
//     {
//         std::cout << "[" << it.first << ", " << it.second << "], ";
//         it++;
//     }
//     std::cout << std::endl;
// }

void printPairs(std::vector<std::pair<int, int> > pairs)
{
    std::cout << "Pairs: ";
    for (size_t i = 0; i < pairs.size(); i++)
        std::cout << "[" << pairs[i].first << "," << pairs[i].second << "]";
    std::cout << std::endl;
}

bool sortSecond(const std::pair<int, int>& left, const std::pair<int,int>& right)
{
    return left.second < right.second;
}

template <typename Container>
void mergeInsertion(Container& c)
{
    // createPairs();
    std::vector<std::pair<int, int> > pairs;
    bool extra = false;
    int extraInt;
    for (size_t i = 0; i + 1 < c.size(); i+=2)
    {
        int a = c[i];
        int b = c[i+1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    // if (c.size() % 2)
    // {
    //     extra = true;
    //     extraInt = c[c.size() - 1];
    // }
    printPairs(pairs);
    // sort second numbers in pairs
    // std::sort(pairs.begin(), pairs.end(), sortSecond); // cant use this -> needs own recursive function
    
    // printPairs(pairs);
    (void)extra;
    (void)extraInt;
    // sortPairs(): recursive function
    // split data into main chain
    // place larger element of each pair in main chain, smaller in pend
    // extras appended to pend
    // recursive call to mergeInsertion (current main chain as input)
    Container main;
    Container pend;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        pend.push_back(pairs[i].first);
        main.push_back(pairs[i].second);
    }
    if (extra)
        pend.push_back(extraInt);
    printContainerContents(main, "Main: ");
    printContainerContents(pend, "pend: ");
    std::cout << "main size: " << main.size() << std::endl;
    if (main.size() == 1)
    {
        int second = main[0];
        main[0] = pend[0];
        main.push_back(second);
        printContainerContents(main, "final Main: ");
        return;
    }
    mergeInsertion(main);
    // create jacobsthal sequence
    // binary insertion
}

int main(int argc, char **argv)
{
    errorHandling(argc, argv);
    printBefore(argc, argv);

    std::vector<int> vec;
    std::deque<int> deq;
    putInContainer(vec, argc, argv);
    putInContainer(deq, argc, argv);
    // printContainerContents(vec, "Vector: ");
    // printContainerContents(deq, "Deque: ");
    mergeInsertion(vec);
    // printOutput();
    // printTime();
}