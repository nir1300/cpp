#include "PmergeMe.hpp"

// STEPS IN ALGORITHM
// 1. create pairs
// 2. sort inside each pair
// 3. build main chain: take larger elements and recursively sort them
// 4. build pending chain
// 5. insert first pending element at front, insert the rest using jacobsthal order, find position with binary search




int main(int argc, char **argv)
{
    errorHandling(argc, argv);
    PmergeMe cont(argc, argv);
    cont.sort();
}