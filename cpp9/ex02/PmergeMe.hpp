#pragma once

#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <stdlib.h>
#include <deque>
#include <vector>
#include <utility>


// template <class T>

void errorHandling(int argc, char **argv);
void printBefore(int argc, char **argv);

class PmergeMe {
    private:
        // template <typename Container> Container c;
        size_t size;
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
        void sortPairs(std::vector<std::pair<int, int> >& pairs, size_t order);
        // void insertPairs(std::vector<std::pair<int, int> >& pairs, int order);
        std::vector<int> generateJacob();
        void printJacob(std::vector<int> jacob);
        template <typename Container> void binaryInsertionJacob(Container& main, Container& pend, Container& partners);
        template <typename Container> void isSorted(Container& main);
        // nested exception classes
        // class GradeTooHighException: public std::exception {
        //     public:
        //         virtual const char* what() const throw();
        // };

        // class GradeTooLowException: public std::exception {
        //     public:
        //         virtual const char* what() const throw();
        // };
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
            while (str[j] == ' ')
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