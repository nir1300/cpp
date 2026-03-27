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

// template <typename Container>
// void mergeInsertion(Container& c, size_t n)
// {
//     for (size_t i = 0; i < ; i++)
//     {

//     }
// }

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

void    printJacob(std::vector<int> jacob)
{
    std::cout << "JACOB: ";
    for (size_t i = 0; i < jacob.size(); i++)
        std::cout << jacob[i] << " ";
    std::cout << std::endl;
}

std::vector<int> PmergeMe::generateJacob()
{
    std::vector<int> jacob;
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
    std::vector<int> gaps;
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
    std::cout << "gaps size:" << gaps.size() << ", size: " << size << std::endl;
    printJacob(gaps);
    return gaps;

}

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
template <typename Container>
void PmergeMe::mergeInsertion(Container& c)
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
    if (c.size() % 2)
    {
        extra = true;
        extraInt = c[c.size() - 1];
    }
    sortPairs(pairs, 2);
    printPairs(pairs);
    (void)extra;
    (void)extraInt;
    // Container main;
    // Container pend;
    // for (size_t i = 0; i < pairs.size(); i++)
    // {
    //     pend.push_back(pairs[i].first);
    //     main.push_back(pairs[i].second);
    // }
    // if (extra)
    //     pend.push_back(extraInt);
    // printContainerContents(main, "Main: ");
    // printContainerContents(pend, "pend: ");
    // std::cout << "main size: " << main.size() << std::endl;
    // if (main.size() > 1)
    //     mergeInsertion(main);
    // // create jacobsthal sequence
    // // binary insertion       
    // // for (size_t i = 0; i < pend.size(); i++)
    // // {
    // //     typename Container::iterator pos =
    // //         std::lower_bound(main.begin(), main.end(), pend[i]);
    // //     main.insert(pos, pend[i]);
    // // }
    // // !! after bigger numbers in pairs are sorted:
    // // main/pend is vector or deque now
    // // main[i] = pairs[i].second;
    // // pend[i] = pairs[i].first;
    // c = main;
    // // insert pend into main
    // printContainerContents(main, "final Main: ");
    // printContainerContents(pend, "final pend: ");
}

void PmergeMe::sort(void)
{
    // start clock
    mergeInsertion(vec);
    // start clock
    // mergeInsertion(deq);
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
    // printContainerContents(vec, "Vector: ");
    // printContainerContents(deq, "Deque: ");
    cont.sort();
    // printOutput();
    // printTime();
}