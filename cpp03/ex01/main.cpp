#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap bob("Bob");
    ScavTrap tim("Tim");
    ScavTrap tmp;

    bob.attack("Tim");
    tim.takeDamage(5);
    tim.beRepaired(2);
    tim.attack("Bob");
    bob.takeDamage(10);
    bob.attack("Tim");
    tim.beRepaired(1000);
}