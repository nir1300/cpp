#include "HumanB.hpp"

HumanB::HumanB(std::string inputName)
{
    name = inputName;
    weapon = NULL;
}

void    HumanB::setWeapon(Weapon& inputWeapon)
{
    this->weapon = &inputWeapon;
}

const std::string   HumanB::getName(void)
{
    return (this->name);
}


void    HumanB::attack(void)
{
    if (weapon == NULL)
        return ;
    std::cout << this->getName() << " attacks with their " << this->weapon->getType() << std::endl;
}