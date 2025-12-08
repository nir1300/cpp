#pragma once

#ifndef __CLAPTRAP_HPP__
#define __CLAPTRAP_HPP__

#include <iostream>

class ClapTrap {
    protected: // changed to protected so derived class has access to these vars
        std::string _name;
        int hitPoints;
        int energyPoints;
        int attackDamage;
    public:
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName(void);

        ClapTrap(std::string name);
        ~ClapTrap();
        ClapTrap(const ClapTrap &other);
        ClapTrap &operator=(const ClapTrap& other);
};



#endif