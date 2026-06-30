#include "PmergeMe.hpp"
#include <deque>

// STEPS IN ALGORITHM
// 1. create pairs
// 2. sort inside each pair
// 3. build main chain: take larger elements and recursively sort them
// 4. build pending chain
// 5. insert first pending element at front, insert the rest using jacobsthal order, find position with binary search

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

int main(int argc, char **argv)
{
    errorHandling(argc, argv);
    PmergeMe cont(argc, argv);
    cont.sort();
}