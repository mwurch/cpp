#include "Zombie.hpp"

int main( void )
{
    int i = 10;

    Zombie* horde = zombieHorde(i, "Olaf");

    for (int j = 0; j < i; j++)
        horde[j].announce();
    delete [] horde;
}