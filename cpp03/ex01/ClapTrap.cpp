#include "ClapTrap.hpp"

ClapTrap::ClapTrap()  : _name("Default"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ClapTrap default constructor was called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) :_name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
	std::cout << "ClapTrap constructor with one argument was called" << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & src)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_attackDamage = src._attackDamage;
		this->_energyPoints = src._energyPoints;
		this->_hitPoints = src._hitPoints;
		this->_name = src._name;
	}
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap copy constructor was called" << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor was called" << std::endl;
}


// ClapTrap <name> attacks <target>, causing <damage> points of damage!
void    ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
		std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
	else
	{
		if (this->_energyPoints == 0)
			std::cout << "ClapTrap " << this->_name << " is exhausted and can't attack!" << std::endl;
		else if (this->_hitPoints == 0)
			std::cout << "ClapTrap " << this->_name << " has not enough hit points to attack it's target!" << std::endl;		
	}
	this->_energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints - static_cast<int>(amount) < 0)
		this->_hitPoints = 0;
	else	
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount << " damage! Hit points left: <" << this->_hitPoints <<">" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0 || this->_energyPoints == 0)
	{
		if (this->_hitPoints == 0)
			std::cout << "ClapTrap " << this->_name << " was not able to repaire itself! " << this->_name << " died!" <<std::endl; 
		else if (this->_energyPoints == 0)
			std::cout << "ClapTrap " << this->_name << " has not enough energy points to repaire itself!" << std::endl; 

	}
	else
	{
		if (this->_hitPoints + amount > 10)
			this->_hitPoints = 10;
		else
			this->_hitPoints = this->_hitPoints + amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself and restored " << amount << " hit points! " << this->_hitPoints <<"/10 hit points left!" << std::endl; 
		this->_energyPoints--;
	}
}
