#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <exception>

class Span
{
    private:

        std::vector<int>    _vec;
        size_t              _max;
        Span();

    public:

        Span(size_t n);
        Span(Span const & src);
        ~Span();

        Span & operator=(Span const & src);

        void    addNumber(int i);
        template <typename Inputit>
        void    fillSpan(Inputit begin, Inputit end);

        long    shortestSpan(void);
        long    longestSpan(void);
};

template <typename Inputit>
void    Span::fillSpan(Inputit begin, Inputit end)
{
    if (static_cast<size_t>(std::distance(begin, end)) > _max)
        throw (std::out_of_range("The given container has to many entries"));
    for (Inputit it = begin; it != end; it++)
        addNumber(*it);
}

#endif