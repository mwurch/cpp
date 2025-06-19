#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <exception>
#include <iostream>

template < typename T >
class MutantStack : public std::stack<T> 
{
    public:
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        typedef typename std::stack<T>::container_type::iterator iterator;
        
        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const &src) : std::stack<T>(src) {}
        ~MutantStack() {}
        MutantStack &operator=(MutantStack const & src)
        {
            if (this != &src)
                std::stack<T>::operator=(src);
            return *this;
        }

        iterator begin()
        {
            return (this->c.begin());
        }

        iterator end()
        {
            return (this->c.end());
        }

        const_iterator begin() const
        {
            return (this->c.begin());
        }

        const_iterator end() const
        {
            return (this->c.end());
        }

        T & operator[](size_t index)
        {
            if (this->c.size() <= index)
            throw (std::out_of_range("The given index is out of range"));
            iterator  it= this->begin();
            std::advance(it, index);
            return (*it);
        }

        const T & operator[](size_t index) const
        {
            if (this->c.size() <= index)
            throw (std::out_of_range("The given index is out of range"));
            const_iterator  it= this->begin();
            std::advance(it, index);
            return (*it);
        }

        


};



#endif