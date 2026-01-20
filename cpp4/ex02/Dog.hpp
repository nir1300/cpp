#pragma once

#ifndef __DOG_HPP__
#define __DOG_HPP__

#include <iostream>
#include "Animal.hpp"

class Dog: public Animal {
    public:
        void makeSound() const;
        // Orthodox Canonical Form
        Dog();
        ~Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog& other);
};



#endif