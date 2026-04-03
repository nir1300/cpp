#include "PmergeMe.hpp"

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
void PmergeMe::binaryInsertionExtra(Container& main, int extra)
{
        int lo = 0;
        int hi = main.size();
        while (lo < hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (extra > main[mid])
                lo = mid + 1;
            else
                hi = mid;
        }
        main.insert(main.begin()+lo, extra);
}

template <typename Container> 
bool PmergeMe::isSorted(Container& main)
{
    for (size_t i = 0; i+1 < main.size(); i++)
    {
        if (main[i] > main[i+1])
        {
            // std::cout << "ERROR - Sorted incorrectly!" << std::endl;
            return false;
        }
    }
    if (main.size() != size)
    {
        // std::cout << "ERROR - Sorted incorrectly!" << std::endl;
        return false;
    }
    return true;
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
    bool odd = false;
    int extraNum;
    if (c.size() % 2)
    {
        odd = true;
        extraNum = c[c.size() - 1];
    }
    mergeSort(pairs);
    // create main and pend chain
    Container main;
    Container pend;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        pend.push_back(pairs[i].first);
        main.push_back(pairs[i].second);
    }
    Container partners = main;
    binaryInsertionJacob(main, pend, partners);
    if (odd)
        binaryInsertionExtra(main, extraNum);
    c = main;
}

void PmergeMe::sort(void)
{
    // TIME WRONG -> needs data management part as well
    std::vector<int> before = vec;

    if (size == 1 || isSorted(vec))
    {
        std::cout << "Already sorted" << std::endl;
        return;
    }
    clock_t start = clock();
    mergeInsertion(deq);
    clock_t end = clock();
    double elapsedDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    start = clock();
    mergeInsertion(vec);
    end = clock();
    double elapsedVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;

    printContainerContents(before, "Before: ");
    printContainerContents(deq, "After:  ");

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
    std::vector<int> vec;
    std::deque<int> deq;
    putInContainer(vec, argc, argv);
    putInContainer(deq, argc, argv);
    PmergeMe cont(vec, deq);
    cont.sort();
}