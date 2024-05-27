#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:

        size_t  _size;
        T*      _arr;

    public:

        Array(void) : _size(0), _arr(NULL) {}
        Array(unsigned int i) : _size(i), _arr(new T[i]) {}
        Array(Array const & src) : _size(0), _arr(NULL)
        {
            *this = src;
        }
        ~Array() { delete [] _arr;}


        Array & operator=(Array const & src)
        {
            if (this != &src)
            {
                delete [] this->_arr;
                this->_arr = new T[src._size];
                for (size_t i = 0; i < src._size; i++)
                    this->_arr[i] = src._arr[i];
                this->_size = src._size;
            }
            return (*this);
        }

        T & operator[](size_t & index)
        {
            if (index >= this->_size)
                throw (std::out_of_range("The given index is out of range of this array"));
            return (this->_arr[index]);
        }

        const T & operator[](size_t const & index)
        {
            if (index >= this->_size)
                throw (std::out_of_range("The given index is out of range of this array"));
            return (this->_arr[index]);
        }

        size_t size(void) const
        {
            return this->_size;
        }
};

#endif