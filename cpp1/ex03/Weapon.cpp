#include "Weapon.hpp"

Weapon::Weapon(std::string weaponType)
{
    type = weaponType;
}

Weapon::~Weapon(void)
{
    ;
}

const std::string& Weapon::getType(void)
{
    return (this->type);
}

void    Weapon::setType(std::string newType)
{
    this->type = newType;
}
