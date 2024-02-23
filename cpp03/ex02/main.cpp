#include "FragTrap.hpp"

int main(void)
{
    FragTrap bob("Bob");
    FragTrap tim("Tim");
    FragTrap tmp;

    bob.attack("Tim");
    tim.takeDamage(5);
    tim.beRepaired(2);
    tim.attack("Bob");
    bob.takeDamage(10);
    bob.attack("Tim");
    tim.beRepaired(1000);
    tmp = bob;
    tmp.highFivesGuys();
}