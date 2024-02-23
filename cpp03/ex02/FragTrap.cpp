#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "\033[33m" << "FragTrap default constructor was called" << "\033[0m" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "\033[33m" << "FragTrap with 1 argument constructor was called" << "\033[0m" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{
    std::cout << "\033[33m" << "FragTrap destructor was called" << "\033[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
    std::cout << "\033[33m" << "FragTrap copy constructor was called" << "\033[0m" << std::endl;
    *this = src;
}

FragTrap & FragTrap::operator=(FragTrap const &src)
{
    std::cout << "\033[33m" << "FragTrap copy assign operator was called" << "\033[0m" << std::endl;
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    std::cout << "\033[33m" << "FragTrap " << this->_name<< " asks to high five!" << "\033[0m" << std::endl;
}