#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : name(name) , weapon(NULL)
{

}

HumanB::~HumanB () {}

std::string    HumanB::getName()
{
    return (this->name);
}

void    HumanB::setWeapon(Weapon &weapon) 
{
    this->weapon = &weapon;
}

void    HumanB::attack()
{
    std::cout << getName() << " attacks with their " << weapon->getType() << std::endl;
}