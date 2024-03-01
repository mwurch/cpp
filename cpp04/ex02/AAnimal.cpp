#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Default")
{
    std::cout << "\033[36m" << "AAnimal default constructor was called!" << "\033[0m" << std::endl;
    this->brain = new Brain();
}

AAnimal::AAnimal(std::string type) : brain(new Brain()), type(type)
{
    std::cout << "\033[36m" << "AAnimal constructor with one argument was called!" << "\033[0m" << std::endl;
}

AAnimal::~AAnimal()
{
    std::cout << "\033[36m" << "AAnimal destructor was called!" << "\033[0m" << std::endl;
    delete this->brain;
}

AAnimal::AAnimal(AAnimal const & src) : brain(new Brain(*src.brain)), type(src.type)
{
    std::cout << "\033[36m" << "AAnimal copy constructor was called!" << "\033[0m" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const & src)
{
    std::cout << "\033[36m" << "AAnimal copy assign operator was called!" << "\033[0m" << std::endl;
    if (this != &src)
    {
        this->type = src.type;
        delete this->brain;
        this->brain = new Brain(*src.brain);
    }
    return (*this);
}