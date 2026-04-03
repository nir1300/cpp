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
        std::vector<int> vec;
        std::deque<int> deq;
    public:
        // Orthodox Canonical Form
        PmergeMe(std::vector<int> vec, std::deque<int> deq);
        ~PmergeMe(); 
        PmergeMe(const PmergeMe &other);
        PmergeMe &operator=(const PmergeMe& other);

        template <typename Container> void mergeInsertion(Container& c);
        void sort(void);
        std::vector<int> generateJacob();
        void printJacob(std::vector<int> jacob);
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

#endif