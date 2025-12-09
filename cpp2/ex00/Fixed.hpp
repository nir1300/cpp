#pragma once

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>

class Fixed {
    private:
        int fpn;
        static const int fractBits = 8;
    public:
        Fixed(void);
        ~Fixed(void);
        Fixed(const Fixed &other); //copy constructor
        Fixed &operator=(const Fixed &other); //copy assignment operator overload
        int getRawBits(void) const;
        void setRawBits (int const raw);
};

#endif