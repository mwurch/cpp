#include <random>
#include <iostream>
#include <exception>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    

}

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
            std::cout << "A was created!" << std::endl;
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

void    idenify(Base& p)
{
    try{
        dynamic_cast<A &>(p);
        std::cout << "The referance is of type A" << std::endl;
        return ;
    }catch(std::exception &e) {std::cout << e.what() << std::endl;}
    try{
        dynamic_cast<B &>(p);
        std::cout << "The referance is of type B" << std::endl;
        return ;
    }catch( std::exception &e) {std::cout << e.what() << std::endl;}
    try{
        dynamic_cast<C &>(p);
        std::cout << "The referance is of type C" << std::endl;
        return ;
    }catch(std::exception &e) {std::cout << e.what() << std::endl;}
}