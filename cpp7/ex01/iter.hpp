#pragma once

#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T> void printArray(const T& i)
{
    std::cout << i << std::endl;
}

template <typename T, typename F> void iter(T* arr, const int len, F f)
{
    for (int i = 0; i < len; i++)
        f(arr[i]);
}


#endif