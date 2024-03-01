#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "AAnimal.hpp"

int main()
{

    Animal *dogPtr = new Dog();
    AAnimal *catPtr = new Cat();
    //AAnimal *aanimalPtr = new AAnimal();

    dogPtr->makeSound();
    catPtr->makeSound();
   
    delete dogPtr;
    delete catPtr;
    return 0;
}