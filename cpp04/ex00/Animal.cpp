#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "\033[36m" << "Animal constructor was called!" << "\033[0m" << std::endl;
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