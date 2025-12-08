#include "HumanA.hpp"

HumanA::HumanA(std::string inputName, Weapon& inputWeapon) : name(inputName), weapon(inputWeapon) {} // list initialization

const std::string   HumanA::getName(void)
{
    return (this->name);
}

void    HumanA::attack(void)
{
    std::cout << this->getName() << " attacks with their " << this->weapon.getType() << std::endl;
}