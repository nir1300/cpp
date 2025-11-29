#pragma once

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
        // constructor and deconstructor
        Zombie(std::string str);
        ~Zombie(void);
        // member functions
       void         announce(void); 
};


Zombie*      newZombie(std::string name);
void         randomChump(std::string name);

#endif