#include "Zombie.hpp"

Zombie::Zombie(std::string str) {
    name = str;
    // announce();
}

Zombie::~Zombie(void) {
    std::cout << this->name << " has been destroyed!! RIP" << std::endl;
}

void         Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
