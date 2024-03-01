#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    std::cout << "\033[31m" << "Cat default constructor was called!" << "\033[0m" << std::endl;
}

Cat::~Cat()
{
    std::cout << "\033[31m" << "Cat destructor was called!" << "\033[0m" << std::endl;
}

Cat::Cat(Cat const & src) : AAnimal(src)
{
    std::cout << "\033[31m" << "Cat copy constructor was called!" << "\033[0m" << std::endl;
    *this = src;
}

Cat & Cat::operator=(Cat const & src)
{
    std::cout << "\033[31m" << "Cat copy assign operator was called!" << "\033[0m" << std::endl;
    this->type = src.type;
    return (*this);
}

void    Cat::makeSound(void)
{
    std::cout << "\033[31m" << "Miao! Miao!" << "\033[0m" << std::endl;
}