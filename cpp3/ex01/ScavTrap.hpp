#pragma once

#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include <iostream>

class ScavTrap {
    private:
        std::string _name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName(void);

        // ScavTrap(std::string name);
        // ~ScavTrap();
        // ScavTrap(const ScavTrap &other);
        // ScavTrap &operator=(const ScavTrap& other);
};



#endif