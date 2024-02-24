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
    std::cout << std::endl << std::endl << "======================================" << std::endl;
    const Animal* test = new Cat();
    delete test;
    test = zoo[0];
    std::cout << test << "  " << zoo[0] << std::endl;
    test->makeSound();
    for (int i = 0; i < 10; i++)
        delete zoo[i];
    

    Animal* animalPtr = new Cat();
    Cat* copiedCatPtr = new Cat(*dynamic_cast<Cat*>(animalPtr));

    std::cout << animalPtr->getBrain() << "  " << copiedCatPtr->getBrain() << std::endl;

    delete animalPtr;
    delete copiedCatPtr;
    return 0;
}