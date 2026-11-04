#include "Zombie.hpp"

int main(void)
{
    Zombie one("Foo");
    one.announce();
    Zombie *two = newZombie("Newy");
    two->announce();
    randomChump("Chumpy");
    delete(two);
}