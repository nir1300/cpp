#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->fpn = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) // converts int to fixed point value
{
    this->fpn = num << this->fractBits;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) // converts float to fixed point value
{
    // leftshift = multiply by powers of 2
    // 1 << 8 == 2^8
    // use roundf -> otherwise might be one off (float to int always rounds down ), e.g.. 537.6 would become 537 -> should be 538 
    this->fpn = roundf(num * (1 << this->fractBits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fpn = other.getRawBits();
} 

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    this->setRawBits(other.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const
{
    return this->fpn;
}

void Fixed::setRawBits(int const raw)
{
    this->fpn = raw;
}

std::ostream &operator<<(std::ostream& out, const Fixed& num)
{
    out << num.toFloat();
    return out;
}

float Fixed::toFloat(void) const
{
    return static_cast<float>(this->fpn) / (1 << this->fractBits);
}

int Fixed::toInt(void) const
{
    // rightshift = divide by powers of 2
    // similiar to above function (both divide by powers of 2) but fpn >> 8 truncates
    return (this->fpn >> this->fractBits);
}
