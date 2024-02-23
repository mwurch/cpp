#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Cat")
{
    std::cout << "\033[33m" << "WrongCat default constructor was called!" << "\033[0m" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "\033[33m" << "WrongCat destructor was called!" << "\033[0m" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src.type)
{
    std::cout << "\033[33m" << "WrongCat copy constructor was called!" << "\033[0m" << std::endl;
    *this = src;
}

WrongCat & WrongCat::operator=(WrongCat const & src)
{
    std::cout << "\033[33m" << "WrongCat copy assign operator was called!" << "\033[0m" << std::endl;
    this->type = src.type;
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    std::cout << "\033[33m" << "Miao! Miao!" << "\033[0m" << std::endl;
}