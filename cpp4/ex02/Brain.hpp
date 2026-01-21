#pragma once

#ifndef __BRAIN_HPP__
#define __BRAIN_HPP__

#include <iostream> 

class Brain {
    private: 
        std::string ideas[100]; 
    public:
        // const std::string getType() const;
        // virtual void makeSound() const; // virtual in base class means it is redefined in derived class => runtime polymorphism, call correct function via base class pointer/reference
        // Orthodox Canonical Form
        Brain();
        ~Brain(); // if base class has any virtual functions, destructor should be virtual too -> important for cleanup
        Brain(const Brain &other);
        Brain &operator=(const Brain& other);
};



#endif