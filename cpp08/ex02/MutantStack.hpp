#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <exception>
#include <iostream>

template < typename T >
class MutantStack : std::stack<T> 
{
    public:

        typedef typename std::stack<T>::container_type::iterator it;
        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const &src) : std::stack(src) {}
        ~MutantStack() {}
        MutantStack &operator=(MutantStack const & src)
        {
            if (this != &src)
                std::stack<T>::operator=(src);
            return *this;
        }

        it begin()
        {
            return (this->c.begin());
        }

        it end()
        {
            return (this->c.end());
        }

        T & operator[](size_t index)
        {
            it iterator = this->begin();
            if (this->c.size() <= index)
                throw (std::out_of_range("The given index is out of range"));
            std::advance(iterator, index);
            return (*iterator);
        }

        


};



#endif