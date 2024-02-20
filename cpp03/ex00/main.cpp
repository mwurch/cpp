#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap bob("Bob");
    ClapTrap tim("Tim");
    ClapTrap tmp;

    bob.attack("Tim");
    tim.takeDamage(5);
    tim.beRepaired(2);
    tim.attack("Bob");
    bob.takeDamage(10);
    bob.attack("Tim");
    tim.beRepaired(1000);
}