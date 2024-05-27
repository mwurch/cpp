#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <exception>

class IntNotFoundException : public std::invalid_argument
{
    public:
        IntNotFoundException() : invalid_argument("Integer was not found") {}
};

template <typename T >
typename T::iterator easyfind(T & container, int i)
{
    typename T::iterator it = std::find(container.begin(), container.end(), i);
    if (it != container.end())
        return it;
    else 
        throw (IntNotFoundException());
}

#endif