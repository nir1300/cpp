#pragma once

#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <cmath>

class Fixed; 

std::ostream &operator<<(std::ostream& out, const Fixed& num);


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

        // overload operators
        // comparison operators
        bool operator>(const Fixed& num) const;
        bool operator<(const Fixed& num) const;
        bool operator>=(const Fixed& num) const;
        bool operator<=(const Fixed& num) const;
        bool operator==(const Fixed& num) const;
        bool operator!=(const Fixed& num) const;

        // arithmetic operators
        const Fixed operator+(const Fixed& num) const;
        const Fixed operator-(const Fixed& num) const;
        const Fixed operator*(const Fixed& num) const;
        const Fixed operator/(const Fixed& num) const;

        // in-/decrement operators
        Fixed operator++();
        const Fixed operator++(int);
        Fixed operator--();
        const Fixed operator--(int);
        
        // min/max overload
        // static because it belongs to class not specific object
        static Fixed min(Fixed& num1, Fixed& num2);
        static const Fixed min(const Fixed& num1, const Fixed& num2);
        static Fixed max(Fixed& num1, Fixed& num2);
        static const Fixed max(const Fixed& num1, const Fixed& num2);
};

#endif