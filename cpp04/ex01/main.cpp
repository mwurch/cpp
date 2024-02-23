#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

    const Animal* zoo[10];

    for (int i = 0; i < 10; i ++)
    {
        if ((i & 1) == 1)
            zoo[i] = new Dog();
        else
            zoo[i] = new Cat();
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << i << std::endl;
        zoo[i]->makeSound();
    }
    for (int i = 0; i < 10; i++)
        delete zoo[i];
    return 0;
}