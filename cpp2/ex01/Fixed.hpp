#pragma once

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

    
class Fixed {
    private:
        int fpn;
        static const int fractBits = 8;
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num); 
        ~Fixed(void);
        Fixed(const Fixed &other); //copy constructor
        Fixed &operator=(const Fixed &other); //copy assignment operator overload
        int getRawBits(void) const;
        void setRawBits (int const raw);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream &operator<<(std::ostream& out, const Fixed& num);

#endif