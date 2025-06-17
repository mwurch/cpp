#include "iter.hpp"

template <typename T>
void    foo(T& i)
{
    i++;
}

int main(void)
{
    int arr[] = {1, 2, 3};
    char arr1[] = {'1', '2', '3'};
    printArr(arr, 3);
    iter(arr, 3, foo<int>);
    printArr(arr, 3);
    
    printArr(arr1, 3);
    iter(arr1, 3, foo<char>);
    printArr(arr1, 3);
    return 0;
}