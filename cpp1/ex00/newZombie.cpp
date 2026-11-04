#include "Zombie.hpp"

Zombie*      newZombie(std::string name)
{
    Zombie *monster = new Zombie(name);
    // monster.announce();
    return (monster);
}
