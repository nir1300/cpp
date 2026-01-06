#pragma once

#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap { 
    public:
        void guardGate();
        explicit ScavTrap(std::string name);
        ScavTrap(const ScavTrap& other);
        ScavTrap &operator=(const ScavTrap& other);
        ~ScavTrap();
        void attack(const std::string& target);
};



#endif