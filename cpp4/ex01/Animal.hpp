#pragma once

#ifndef __ANIMAL_HPP__
#define __ANIMAL_HPP__

#include <iostream>

class Animal {
    protected: 
        std::string type;
    public:
        const std::string getType() const;
        virtual void makeSound() const; // virtual in base class means it is redefined in derived class => runtime polymorphism, call correct function via base class pointer/reference
        // Orthodox Canonical Form
        Animal();
        virtual ~Animal(); // if base class has any virtual functions, destructor should be virtual too -> important for cleanup, will not compile without virtual destructor, to avoid leaks
        Animal(const Animal &other);
        Animal &operator=(const Animal& other);
};



#endif