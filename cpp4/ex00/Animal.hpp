#pragma once

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal {
    protected: 
        std::string type;
    public:
        void makeSound();
        // Orthodox Canonical Form
        Animal(std::string InputType);
        ~Animal();
        Animal(const Animal &other);
        Animal &operator=(const Animal& other);
};



#endif