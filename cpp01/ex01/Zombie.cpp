#include "Zombie.hpp"

Zombie::Zombie() : name("Default Zombie")
{
	std::cout << "Zombie constructor was called" << std::endl;
}

Zombie::Zombie(std::string name) : name(name)
{
	std::cout << "Zombie with 1 argument Constructor was called" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " has died" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void			Zombie::setName(std::string name)
{
	this->name = name;
}
