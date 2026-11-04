#pragma once

#ifndef __WEAPON_HPP__
#define __WEAPON_HPP__

#include <iostream>

class Weapon {
    private:
        std::string type; 
    public:
        const std::string&   getType(void);
        void          setType(std::string newType);
        Weapon(std::string weaponType);
        ~Weapon(void);
};


#endif