#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Hordemember has been created" << std::endl;
}

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
	if (this->name == "Foo")
		std::cout << this->name << ":  BraiiiiiiinnnzzzZ..." << std::endl;
	else
		std::cout << '<' << this->name << '>' << ":  BraiiiiiiinnnzzzZ..." << std::endl;
}

void			Zombie::setName(std::string name)
{
	this->name = name;
}