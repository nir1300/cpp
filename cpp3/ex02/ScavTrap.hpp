#pragma once

#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap { // use public or protected here?
    public:
        void guardGate();
        explicit ScavTrap(std::string name); // what does explicit mean here?
        ScavTrap(const ScavTrap& other);
        ScavTrap &operator=(const ScavTrap& other);
        ~ScavTrap();
        void attack(const std::string& target);
};



#endif