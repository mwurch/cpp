#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    std::cout << "\033[32m" << "ScavTrap default constructor was called" << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "\033[32m" << "ScavTrap 1 argument constructor was called" << "\033[0m" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "\033[32m" << "ScavTrap destructor was called" << "\033[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
    std::cout << "\033[32m" << "ScavTrap copy constructor was called" << "\033[0m" << std::endl;
    *this = src;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & src)
{
    std::cout << "\033[32m" << "ScavTrap copy assign operator was called" << "\033[0m" << std::endl;
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;
    return (*this);
}

void    ScavTrap::guardGate(void)
{
    std::cout << "\033[32m" << "ScavTrap " <<  this->_name << " is now in Gatekeeper Mode!" << "\033[0m" << std::endl;
}

void    ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
		std::cout << "\033[32m" << "ScavTrap " << this->_name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << "\033[0m" << std::endl;
	else
	{
		if (this->_energyPoints == 0)
			std::cout << "\033[32m" << "ScavTrap " << this->_name << " is exhausted and can't attack!" << "\033[0m" << std::endl;
		else if (this->_hitPoints == 0)
			std::cout << "\033[32m" << "ScavTrap " << this->_name << " has not enough hit points to attack it's target!" << "\033[0m" << std::endl;		
	}
	this->_energyPoints--;
}