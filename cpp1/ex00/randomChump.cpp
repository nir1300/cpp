#include "Zombie.hpp"

void         randomChump(std::string name)
{
    Zombie chumpmonster(name);
    chumpmonster.announce();
}