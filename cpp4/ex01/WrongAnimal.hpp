#pragma once

#ifndef __WRONGANIMAL_HPP__
#define __WRONGANIMAL_HPP__

#include <iostream>

class WrongAnimal {
    protected: 
        std::string type;
    public:
        const std::string getType() const;
        void makeSound() const;
        // Orthodox Canonical Form
        WrongAnimal();
        ~WrongAnimal();
        WrongAnimal(const WrongAnimal &other);
        WrongAnimal &operator=(const WrongAnimal& other);
};



#endif