#include <cstddef>
#include "Harl.hpp"

Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug()
{
    std::cout << "\033[32m";
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
    std::cout << "\033[0m";

}

void Harl::info()
{
    std::cout << "\033[33m";
    std::cout << "I cannot believe adding extra bacon costs more money. You didnt put enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
    std::cout << "\033[0m";
}

void Harl::warning()
{
    std::cout << "\033[34m";
    std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for years whereas you started working here since last month." << std::endl;
    std::cout << "\033[0m";
}

void Harl::error()
{
    std::cout << "\033[35m";
    std::cout << "This is unacceptable! I want to speak to the manager now" << std::endl;
    std::cout << "\033[0m";
}

void Harl::complain(std::string level)
{
    std::string levels[] = { "info", "warning", "debug", "error"};
    void    (Harl::*functionPtr[])(void) = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            (this->*functionPtr[i])();
    }
}