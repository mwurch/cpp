#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "\033[32m" << "Dog default constructor was called!" << "\033[0m" << std::endl;
}

Dog::~Dog()
{
    std::cout << "\033[32m" << "Dog destructor was called!" << "\033[0m" << std::endl;
}

Dog::Dog(Dog const & src) : Animal(src)
{
    std::cout << "\033[32m" << "Dog copy constructor was called!" << "\033[0m" << std::endl;
    *this = src;
}

Dog & Dog::operator=(Dog const & src)
{
    std::cout << "\033[32" << "Dog copy assign operator was called!" << "\033[0m" << std::endl;
    this->type = src.type;
    return (*this);
}

void    Dog::makeSound(void) const
{
    std::cout << "\033[32m" << "Woof! Woof!" << "\033[0m" << std::endl;
}