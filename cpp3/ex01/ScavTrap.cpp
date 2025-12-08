#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name) // name is already set in ClapTrap(name)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "The ScavTrap constructor has been called." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "The ScavTrap destructor has been called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other) // vars already copied in ClapTrap(other)
{
    std::cout << "The ScavTrap copy constructor has been called." << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other) // cannot call list initialiser here because assignment operator is not a constructor
{
    std::cout << "The ScavTrap copy assignment operator has been called." << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other); // call here to update vars
    }
    return (*this);
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap guards the gate." << std::endl;
}

void ScavTrap::attack(const std::string& target)
{   
    if (!this->energyPoints || !this->hitPoints)
    {
        std::cout << "ScavTrap " << this->_name << " doesn't have enough energy points to attack." << std::endl;
        return ;
    }
    this->energyPoints--;
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}