#include "Zombie.hpp"

int main( void )
{
    Zombie* heapZombie;
    heapZombie = newZombie("Guenther");
    std::cout << "..........................." << std::endl;
    randomChump("Foo");
    std::cout << "..........................." << std::endl;
    heapZombie->announce();
    delete heapZombie;
    return (0);
}