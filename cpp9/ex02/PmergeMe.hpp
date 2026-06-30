#pragma once

#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <stdlib.h>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>
#include <ctime>
#include <iomanip>

// template <class T>

void errorHandling(int argc, char **argv);
void printBefore(int argc, char **argv);

class PmergeMe {
    private:
        // template <typename Container> Container c;
        size_t size;
        int comparisons;
        int argcStored;
        char **argvStored;
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        // Orthodox Canonical Form
        PmergeMe(int argc, char **argv);
        ~PmergeMe(); 
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe& other);

        template <typename Container, typename PairContainer> void mergeInsertion(Container& c, PairContainer& pairs);
        void sort();
 
        void printJacob(std::vector<int> jacob);
        template <typename Container> Container generateJacob(void);
        template <typename Container> void binaryInsertionJacob(Container& main, Container& pend, Container& partners);
        template <typename Container> void binaryInsertionExtra(Container& main, int extra);
        template <typename Container> bool isSorted(Container& main);
};

template <typename Container>
void putInContainer(Container& c, int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        std::string str = argv[i];
        for (size_t j = 0; j < str.length(); j++)
        {
            int res = 0;
            while (str[j] && str[j] == ' ')
                j++;
            if (!str[j] || !isdigit(str[j]))
                continue;
            while (str[j] && isdigit(str[j]))
            {
                res = (res * 10) + (str[j] - '0');
                j++;
            }
            c.push_back(res);
        }
    }
}


template <typename Container>
void printContainerContents(Container& c, std::string str)
{
    std::cout << str;
    typename Container::iterator it = c.begin();
    while (it != c.end())
        std::cout << *it++ << " ";
    std::cout << std::endl;
}

template <typename PairContainer>
void mergePairs(PairContainer& arr, PairContainer& leftArr, PairContainer& rightArr)
{
    size_t r = 0;
    size_t l = 0;
    for (size_t a = 0; a < arr.size(); a++)
    {
        if ((r < rightArr.size() && l < leftArr.size() && leftArr[l].second > rightArr[r].second) || (l >= leftArr.size() && r < rightArr.size()))
        {
            arr[a] = rightArr[r];
            r++;
        }
        //

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

template <typename PairContainer>
void mergeSort(PairContainer& pairs)
{
    PairContainer leftArr, rightArr;
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
    mergePairs(pairs, leftArr, rightArr);
}

template <typename Container>
void PmergeMe::binaryInsertionJacob(Container& main, Container& pend, Container& partners)
{
    Container jacob = generateJacob<Container>();
    main.insert(main.begin(), pend[0]);
    for (size_t i = 1; i < jacob.size(); i++)
    {
        if ((size_t)jacob[i] >= pend.size())
            continue;
        int jacobNum = jacob[i];
        int elementToInsert =  pend[jacobNum];
        int num = partners[jacobNum];
        int lo = 0;
        int hi = main.size();
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

template <typename Container, typename PairContainer>
void PmergeMe::mergeInsertion(Container& c, PairContainer& pairs)
{
    for (size_t i = 0; i + 1 < c.size(); i+=2)
    {
        int a = c[i];
        int b = c[i+1];
        if (a < b)
            pairs.push_back(std::make_pair(a, b));
        else
            pairs.push_back(std::make_pair(b, a));
        comparisons++;
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

template <typename Container>
Container PmergeMe::generateJacob(void)
{
    Container jacob;
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
    Container gaps;
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

template <typename Container>
void    printJacob(Container jacob)
{
    std::cout << "JACOB: ";
    for (size_t i = 0; i < jacob.size(); i++)
        std::cout << jacob[i] << " ";
    std::cout << std::endl;
}

#endif