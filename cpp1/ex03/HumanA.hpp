#pragma once

#ifndef __HUMANA_HPP__
#define __HUMANA_HPP__

#include <iostream>
#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon&      weapon; // needs to be reference, otherwise value will not be updated after resetting the weapon in main
    public:
        HumanA(std::string inputName, Weapon& inputWeapon);
        const std::string   getName(void);
        void                attack(void);
};


#endif