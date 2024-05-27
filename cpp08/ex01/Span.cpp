#include "Span.hpp"

Span::Span() {}
Span::~Span() {}

Span::Span(size_t n) : _max(n) {}
Span::Span(Span const & src) :_vec(src._vec.begin(), src._vec.end()), _max(src._max) {}

Span & Span::operator=(Span const & src) 
{
    if (this != &src)
    {
        this->_max = src._max;
        this->_vec = src._vec;
    }
    return (*this);
}

void    Span::addNumber(int i)
{
    if (this->_vec.size() < this->_max)
        this->_vec.push_back(i);
    else
        throw std::out_of_range("Span capacity reached it's limit!");
}

long    Span::longestSpan(void)
{
    if (this->_vec.size() <= 1)
        throw( std::logic_error("Can't calculate a span with 1 or fewer numbers"));
    else
    {
        std::sort(_vec.begin(), _vec.end());
        return (static_cast<long>(_vec.back()) - static_cast<long>(_vec.front()));
    }
}

long    Span::shortestSpan(void)
{
    if (this->_vec.size() <= 1)
        throw( std::logic_error("Can't calculate a span with 1 or fewer numbers"));
    else
    {
        std::sort(_vec.begin(), _vec.end());
        return (static_cast<long>(_vec[1]) - static_cast<long>(_vec[0]));
    }
}

