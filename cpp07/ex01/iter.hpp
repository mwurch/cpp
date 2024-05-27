#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template < typename T, typename F>
void    iter(T * arr, size_t len, F foo)
{
    for (size_t i = 0; i < len; i++)
        foo(arr[i]);
}

template < typename T >
void    printArr(T * a, size_t len)
{
    for (size_t i = 0; i < len; i++)
        std::cout << "<" << a[i] << "> ";
    std::cout << std::endl;
}

#endif