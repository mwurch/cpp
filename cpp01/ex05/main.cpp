#include <iostream>
#include"Harl.hpp"

int main()
{
    Harl obj;

    std::cout << "Hello" << std::endl;
    obj.complain("debug");
    obj.complain("info");
    obj.complain("warning");
    obj.complain("error");
    obj.complain("Harl");
}