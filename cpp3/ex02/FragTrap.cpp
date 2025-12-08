#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name) // name is already set in ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "The FragTrap constructor has been called." << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "The FragTrap destructor has been called." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other) // vars already copied in ClapTrap(other)
{
    std::cout << "The FragTrap copy constructor has been called." << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap& other) // cannot call list initialiser here because assignment operator is not a constructor
{
    std::cout << "The FragTrap copy assignment operator has been called." << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other); // call here to update vars
    }
    return (*this);
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "[ScavTrap] HIGH FIVE!!" << std::endl;
}
