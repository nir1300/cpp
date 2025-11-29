#include "Zombie.hpp"

Zombie*      newZombie(std::string name)
{
    Zombie *monster = new Zombie(name);
    return (monster);
}
