#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name)
{
	announce();
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " has died" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}