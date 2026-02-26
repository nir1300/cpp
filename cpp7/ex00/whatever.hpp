#pragma once

#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <class T> void swap(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

template <class T> T max(T& x, T& y) 
{
    return (x > y ? x : y);
}

template <class T> T min(T& x, T& y) 
{
    return (x < y ? x : y);
}

#endif