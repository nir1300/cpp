#pragma once

#ifndef __HUMANB_HPP__
#define __HUMANB_HPP__

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    private:
        std::string name;
        Weapon*      weapon;
    public:
        const std::string   getName(void);
        void                attack(void);
        void    setWeapon(Weapon& inputWeapon);
        HumanB(std::string inputName);
};


#endif