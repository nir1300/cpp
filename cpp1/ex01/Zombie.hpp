#pragma once

#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__

#include <iostream>

class Zombie {
    private:
        std::string name;
    public:
    // add constructor!!
        
        void        set_name(std::string name);
        void        announce(void); 
};


Zombie* zombieHorde(int N, std::string name);

#endif