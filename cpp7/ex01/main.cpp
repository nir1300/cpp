#include "iter.hpp"

// void    increase(int& i)
// {
//     i++;
// }

// void    printArray(const int& i)
// {
//     std::cout << i << std::endl;
// }

int main( void ) {
    {
    const int a[] = {1, 2};
    const int c = 2;
    iter(a, c, printArray<int>);
    }
    {
    int a[] = {1, 2};
    const int c = 2;
    iter(a, c, printArray<int>);
    }
    {
    char b[3] = {'h', 'i'};
    iter(b, 2, printArray<char>);
    }
}