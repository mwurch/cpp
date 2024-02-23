#include "Animal.hpp"

Animal::Animal() : type("Default")
{
    std::cout << "\033[36m" << "Animal default constructor was called!" << "\033[0m" << std::endl;
}

Animal::Animal(std::string type) : type(type)
{
    std::cout << "\033[36m" << "Animal constructor with one argument was called!" << "\033[0m" << std::endl;
}

Animal::~Animal()
{
    std::cout << "\033[36m" << "Animal destructor was called!" << "\033[0m" << std::endl;
}

Animal::Animal(Animal const & src)
{
    std::cout << "\033[36m" << "Animal copy constructor was called!" << "\033[0m" << std::endl;
    *this = src;
}

Animal & Animal::operator=(Animal const & src)
{
    std::cout << "\033[36m" << "Animal copy assign operator was called!" << "\033[0m" << std::endl;
    this->type = src.type;
    return (*this);
}

void    Animal::makeSound(void) const
{
    std::cout << "\033[36m" << "**Animal sounds**" << "\033[0m" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}