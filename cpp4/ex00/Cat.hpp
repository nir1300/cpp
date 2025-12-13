#pragma once

#ifndef __CAT_HPP__
#define __CAT_HPP__

#include <iostream>
#include "Animal.hpp"

class Cat: public Animal {
    public:
        void makeSound() const;
        // Orthodox Canonical Form
        Cat();
        ~Cat();
        Cat(const Cat &other);
        Cat &operator=(const Cat& other);
};



#endif