#include "iter.hpp"

void    foo(int & i)
{
    i++;
}

int main(void)
{
    int arr[] = {1, 2, 3};
    printArr(arr, 3);

    iter(arr, 3, foo);
    printArr(arr, 3);
}