#include "Weapon.hpp"

std::string    Weapon::getType( void )
{
    return (this->type);
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}
Weapon::Weapon() : type("fists") {}
Weapon::Weapon(std::string type = "plastic spoon") : type(type) {}
Weapon::~Weapon() {}
