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
    int a[2] = {1, 2};
    iter(a, 2, printArray<int>);

    char b[3] = {'h', 'i'};
    iter(b, 2, printArray<char>);
}