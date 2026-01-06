#pragma once

#ifndef __FRAGTRAP_HPP__
#define __FRAGTRAP_HPP__

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
    public:
        void highFivesGuys(void);
        explicit FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap &operator=(const FragTrap& other);
        ~FragTrap();
};

#endif