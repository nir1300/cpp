#pragma once

#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
    private:
        Brain* brain;
    public:
        Brain* getBrain() const;
        void makeSound() const; // why not virtual?
        // Orthodox Canonical Form
        Cat();
        ~Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat& other);
};



#endif