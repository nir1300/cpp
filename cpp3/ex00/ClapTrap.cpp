#include "ClapTrap.hpp"

void ClapTrap::attack(const std::string& target)
{   
    if (!this->energyPoints || !this->hitPoints)
    {
        std::cout << "ClapTrap " << this->_name << " doesn't have enough energy points to attack." << std::endl;
        return ;
    }
    this->energyPoints--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= unsigned(this->hitPoints))
        this->hitPoints = 0;
    else
        this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (!this->energyPoints || !this->hitPoints)
    {
        std::cout << "ClapTrap " << this->_name << " cannot repair itself." << std::endl;
        return ;
    }
    this->energyPoints--;
    this->hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " repairs itself with " << amount << " hit points!" << std::endl;
}

std::string ClapTrap::getName(void)
{
    return (this->_name);
}

ClapTrap::ClapTrap(std::string name): _name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "The constructor has been called." << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "The destructor has been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "The copy constructor has been called." << std::endl;

}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "The copy assignment operator has been called." << std::endl;
    if (this == &other)
        return (*this);
    this->_name = other._name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    return (*this);
}