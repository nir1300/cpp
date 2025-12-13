#include "Fixed.hpp"

Fixed::Fixed(void)
{
    this->fpn = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
    this->fpn = num << this->fractBits;
    std::cout << "Int Default constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
    this->fpn = roundf(num * (1 << this->fractBits));
    std::cout << "Float Default constructor called" << std::endl;
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
    return (this->fpn >> this->fractBits);
}
