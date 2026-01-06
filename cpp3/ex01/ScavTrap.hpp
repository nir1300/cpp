#pragma once

#ifndef __SCAVTRAP_HPP__
#define __SCAVTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap { // public allows public+protected members to be accessible to derived classes
    public:
        void guardGate();
        explicit ScavTrap(std::string name); // explicit prevents accidental conversion, e.g ScavTrap n = "Nina" is not allowed -> must be ScavTrap n("Nina"), can 
        ScavTrap(const ScavTrap& other); //copy constructor -> dont use explicit here as implicit copying is main point of copy constructor
        ScavTrap &operator=(const ScavTrap& other);
        ~ScavTrap();
        void attack(const std::string& target);
};


#endif