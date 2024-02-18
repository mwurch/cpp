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

Fixed & Fixed::operator=(Fixed const & src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fixedNumber = src.getRawBits();
    return (*this);
}

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

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
    o << src.toFloat();
    return (o);
}