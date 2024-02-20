#include <iostream>
#include <cmath>
#include <ostream>
#include "Fixed.hpp"

Fixed::Fixed(): _fixedNumber(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const n) : _fixedNumber(n << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const n) : _fixedNumber(roundf(n * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

// overloaded  operators

Fixed & Fixed::operator=(Fixed const & src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fixedNumber = src.getRawBits();
    return (*this);
}

bool    Fixed::operator<(Fixed const &src) const
{
    return (this->toFloat() < src.toFloat());
}

bool    Fixed::operator>(Fixed const & src) const
{
    return (this->toFloat() > src.toFloat());
}

bool    Fixed::operator>=(Fixed const & src) const
{
    return (this->toFloat() >= src.toFloat());
}

bool    Fixed::operator<=(Fixed const & src) const
{
    return (this->toFloat() <= src.toFloat());
}

bool    Fixed::operator==(Fixed const & src) const
{
    return (this->toFloat() == src.toFloat());
}

bool    Fixed::operator!=(Fixed const & src) const
{
    return (this->toFloat() != src.toFloat());
}

float    Fixed::operator-(Fixed const & src) const
{
    return (this->toFloat() - src.toFloat());
}

float    Fixed::operator+(Fixed const & src) const
{
    return (this->toFloat() + src.toFloat());
}

float    Fixed::operator*(Fixed const & src) const
{
    return (this->toFloat() * src.toFloat());
}

float    Fixed::operator/(Fixed const & src) const
{
    return (this->toFloat() / src.toFloat());
}

Fixed  Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_fixedNumber++;
    return(tmp);
}

Fixed  Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_fixedNumber--;
    return(tmp);
}

Fixed & Fixed::operator++()
{
    this->_fixedNumber++;
    return (*this);
}

Fixed & Fixed::operator--()
{
    this->_fixedNumber--;
    return (*this);
}
// member functions
int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedNumber);
}
void   Fixed::setRawBits(int const raw) 
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixedNumber = raw;
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>(_fixedNumber / static_cast<float>(1 << _fractionalBits)));
}

int     Fixed::toInt(void) const
{
    return (this->_fixedNumber >> _fractionalBits);
}


Fixed & Fixed::min(Fixed &a, Fixed &b)
{
    if (a > b)
        return (b);
    else
        return (a);
}

const Fixed & Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (b);
    else
        return (a);
}

Fixed & Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

const Fixed & Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
    o << src.toFloat();
    return (o);
}