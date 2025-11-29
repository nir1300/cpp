#include "Zombie.hpp"

void         randomChump(std::string name)
{
    Zombie chumpmonster(name);
    chumpmonster.announce(); // would be printed here twice if i put in constructor
}