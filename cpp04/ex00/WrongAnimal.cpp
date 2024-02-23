#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Default")
{
    std::cout << "\033[36m" << "WrongAnimal default constructor was called!" << "\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
    std::cout << "\033[36m" << "WrongAnimal constructor with one argument was called!" << "\033[0m" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "\033[36m" << "WrongAnimal destructor was called!" << "\033[0m" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src)
{
    std::cout << "\033[36m" << "WrongAnimal copy constructor was called!" << "\033[0m" << std::endl;
    *this = src;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & src)
{
    std::cout << "\033[36m" << "WrongAnimal copy assign operator was called!" << "\033[0m" << std::endl;
    this->type = src.type;
    return (*this);
}

void    WrongAnimal::makeSound(void) const
{
    std::cout << "\033[36m" << "**WrongAnimal sounds**" << "\033[0m" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}