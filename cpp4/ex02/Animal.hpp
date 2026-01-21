#pragma once

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal {
    protected: 
        std::string type;
    public:
        const std::string getType() const;
        virtual void makeSound() const = 0;
        // Orthodox Canonical Form
        Animal();
        virtual ~Animal(); // if base class has any virtual functions, destructor should be virtual too -> important for cleanup
        Animal(const Animal &other);
        Animal &operator=(const Animal& other);
};



#endif