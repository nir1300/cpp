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


// void PmergeMe::insertPairs(std::vector<std::pair<int, int> >& pairs, int order)
// {
//     if (order == 2) // && size % 2 != 0)
//     {
//         printPairs(pairs);
//         return;
//     }
//     for (int i = 0; i + order - 1 < size/2; i += order)
//     {
//         int left = i+order/2-1;
//         int right = i+order-1;
//         if (right > size/2 - 1)
//             break;
//         if (pairs[left].second > pairs[right].second)
//         {
//             for (int j = 0; j < order/2; j++)
//             {
//                 if (i+j+order/2 > size/2-1)
//                     break;
//                 std::swap(pairs[i + j], pairs[i + j + order/2]);
//             }
//         }
//     }
//     // std::cout << "ORDER: " << order << std::endl;
//     // printPairs(pairs);
//     sortPairs(pairs, order * 2);
// }





void PmergeMe::sortPairs(std::vector<std::pair<int, int> >& pairs, size_t order)
{
    // std::cout << "size: " << size << std::endl;
    if (order > size/2)
    {
        // std::cout << "ORDER: " << order << std::endl;
        printPairs(pairs);
        generateJacob();
        // if (size != order) // if size == order -> sorted ??? NOT TRUE
        // insertPairs(pairs,order/2);
        return;
    }
    for (size_t i = 0; i + order - 1 < size/2; i += order)
    {
        size_t left = i+order/2-1;
        size_t right = i+order-1;
        if (right > size/2 - 1)
            break;
        if (pairs[left].second > pairs[right].second)
        {
            for (size_t j = 0; j < order/2; j++)
            {
                if (i+j+order/2 > size/2-1)
                    break;
                std::swap(pairs[i + j], pairs[i + j + order/2]);
            }
        }
    }
    // std::cout << "ORDER: " << order << std::endl;
    // printPairs(pairs);
    sortPairs(pairs, order * 2);
    // std::cout << " final ORDER: " << order << std::endl;
    // insert extras
    // std::vector::insert(iterator position, value)
    // printPairs(pairs);
}

void merge(std::vector<std::pair<int, int> >& arr, std::vector<std::pair<int, int> >& leftArr, std::vector<std::pair<int, int> >& rightArr)
{
    std::vector<std::pair<int, int> > tmp;
    size_t r = 0;
    size_t l = 0;
    for (size_t a = 0; a < arr.size(); a++)
    {
        if ((r < rightArr.size() && l < leftArr.size() && leftArr[l].second > rightArr[r].second) || (l >= leftArr.size() && r < rightArr.size()))
        {
            arr[a] = rightArr[r];
            r++;
        }
        else if ((r < rightArr.size() && l < leftArr.size() && leftArr[l].second < rightArr[r].second) || (l < leftArr.size() && r >= rightArr.size()))
        {
            arr[a] = leftArr[l];
            l++;
        }
        else
            return;
    }
    // std::cout << "merge: ";
    // printPairs(arr);
}

void mergeSort(std::vector<std::pair<int, int> >& pairs)
{
    std::vector<std::pair<int, int> > leftArr, rightArr;
    for (size_t i = 0; i < pairs.size()/2; i++)
        leftArr.push_back(pairs[i]);
    int middle = pairs.size() / 2;
    int j = 0;
    for (size_t i = middle; i < pairs.size(); i++)
    {
        rightArr.push_back(pairs[i]);
        j++;
    }
    // std::cout << "left: ";
    // printPairs(leftArr);
    // std::cout << "right: ";
    // printPairs(rightArr);
    // // condition when to return ??
    if (leftArr.size() > 1)
        mergeSort(leftArr);
    if (rightArr.size() > 1)
        mergeSort(rightArr);
    merge(pairs, leftArr, rightArr);
}

template <typename Container>
void PmergeMe::binaryInsertionJacob(Container& main, Container& pend, Container& partners)
{
    std::vector<int> jacob = generateJacob();
    // printContainerContents(partners, "final partners: ");
    // printContainerContents(main, "final Main: ");
    // printContainerContents(pend, "final pend: ");
    main.insert(main.begin(), pend[0]);
    for (size_t i = 1; i < jacob.size(); i++)
    {
        if ((size_t)jacob[i] >= pend.size())
            continue;
        int jacobNum = jacob[i];
        int elementToInsert =  pend[jacobNum];
        int num = partners[jacobNum];
        int lo = 0;
        int hi;
        for (size_t i = 0; i < main.size(); i++)
        {
            if (main[i] == num)
            {
                hi = i;
                break;
            }
        }
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (elementToInsert > main[mid])
                lo = mid + 1;
            else
                hi = mid;
        }
        main.insert(main.begin()+lo, pend[jacobNum]);
    }
}

template <typename Container> 
void PmergeMe::isSorted(Container& main)
{
    for (size_t i = 0; i+1 < main.size(); i++)
    {
        if (main[i] > main[i+1])
        {
            std::cout << "WRONG" << std::endl;
            return;
        }
    }
    std::cout << "Sorted correctly!" << std::endl;
    std::cout << "main size: " << main.size() << ", actual size: " << size << std::endl;
}

template <typename Container>
void PmergeMe::mergeInsertion(Container& c)
{
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < c.size(); i+=2)
    {
        int a = c[i];
        int b = c[i+1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
    }
    mergeSort(pairs);
    printPairs(pairs);
    // create main and pend chain
    Container main;
    Container pend;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        pend.push_back(pairs[i].first);
        main.push_back(pairs[i].second);
    }
    Container partners = main;
    // if (extra)
    //     pend.push_back(extraInt);
    // printContainerContents(main, "Main: ");
    // printContainerContents(pend, "pend: ");
    // std::cout << "main size: " << main.size() << std::endl;
    binaryInsertionJacob(main, pend, partners);
    c = main;
    // printContainerContents(main, "FINAL MAIN: ");
    // isSorted(main);
}

void PmergeMe::sort(void)
{
    // start clock
    mergeInsertion(deq);
    // std::cout << "Time to process a range of " << size << "elements with std::deque: " << time << " us" << std::endl;

    // start clock
    mergeInsertion(vec);
    // std::cout << "Time to process a range of " << size << "elements with std::vector: " << time << " us" << std::endl;

    printContainerContents(deq, "After: ");
    isSorted(deq);
}

int main(int argc, char **argv)
{
    errorHandling(argc, argv);
    printBefore(argc, argv);

    std::vector<int> vec;
    std::deque<int> deq;
    putInContainer(vec, argc, argv);
    putInContainer(deq, argc, argv);
    PmergeMe cont(vec, deq);
    cont.sort();


}