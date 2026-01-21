#pragma once

#ifndef __WRONGCAT_HPP__
#define __WRONGCAT_HPP__

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    public:
        void makeSound() const;
        // Orthodox Canonical Form
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat &other);
        WrongCat &operator=(const WrongCat& other);
};

#endif