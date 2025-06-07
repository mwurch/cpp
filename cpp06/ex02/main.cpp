#include <random>
#include <iostream>
#include <exception>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"



Base*   generate(void)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 2);

    int number = dis(gen);

    switch(number)
    {
        case(0):
        {
            std::cout << "A was created!" << std::endl;
            return (new A());
        }
        case(1):
        {
            std::cout << "B was created!" << std::endl;
            return (new B());
        }
        case(2):
        {
            std::cout << "C was created!" << std::endl;
            return (new C());
        }
        default:
        {
            std::cerr << "Error" << std::endl;
            return nullptr;
        }
    }
}

void    identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "The pointer is of type A" << std::endl;
    else if(dynamic_cast<B *>(p))
        std::cout << "The pointer is of type B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "The pointer is of type C" << std::endl;
    else
        std::cout << "Invalid pointer" << std::endl;
}

void    identify(Base& p)
{
    try{
        A &a =dynamic_cast<A &>(p);
        (void)a;
        std::cout << "The referance is of type A" << std::endl;
        return ;
    }catch(std::exception &e) {}
    try{
        B& b = dynamic_cast<B &>(p);
        (void)b;
        std::cout << "The referance is of type B" << std::endl;
        return ;
    }catch( std::exception &e) {}
    try{
        C &c = dynamic_cast<C &>(p);
        (void)c;
        std::cout << "The referance is of type C" << std::endl;
        return ;
    }catch( std::exception &e) {}
}

int main(void)
{
    Base* ptr = generate();
    Base& ref = *ptr;

    identify(ptr);
    identify(ref);
}