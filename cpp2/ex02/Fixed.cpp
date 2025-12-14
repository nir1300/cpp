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

// comparison operators
bool Fixed::operator>(const Fixed& num) const
{
    return (this->fpn > num.fpn);
}

bool Fixed::operator<(const Fixed& num) const
{
    return (this->fpn < num.fpn);
}

bool Fixed::operator>=(const Fixed& num) const
{
    return (this->fpn >= num.fpn);
}

bool Fixed::operator<=(const Fixed& num) const
{
    return (this->fpn <= num.fpn);
}

bool Fixed::operator==(const Fixed& num) const
{
    return (this->fpn == num.fpn);
}

bool Fixed::operator!=(const Fixed& num) const
{
    return (this->fpn != num.fpn);
}

// arithmetic operators
const Fixed Fixed::operator+(const Fixed& num) const
{
    return (this->fpn + num.fpn);
}

const Fixed Fixed::operator-(const Fixed& num) const
{
    return (this->fpn - num.fpn);
}

const Fixed Fixed::operator*(const Fixed& num) const
{
    return (this->fpn * num.fpn);
}

const Fixed Fixed::operator/(const Fixed& num) const
{
    return (this->fpn / num.fpn);
}

// min/max operators 

Fixed Fixed::min(Fixed& num1, Fixed& num2)
{
    if (num1.fpn < num2.fpn)
        return (num1.fpn);
    return (num2.fpn);
}

const Fixed Fixed::min(const Fixed& num1, const Fixed& num2)
{
    if (num1.fpn < num2.fpn)
        return (num1.fpn);
    return (num2.fpn);
}

Fixed Fixed::max(Fixed& num1, Fixed& num2)
{
    if (num1.fpn > num2.fpn)
        return (num1.fpn);
    return (num2.fpn);
}

const Fixed Fixed::max(const Fixed& num1, const Fixed& num2)
{
    if (num1.fpn > num2.fpn)
        return (num1.fpn);
    return (num2.fpn);
}

Fixed Fixed::operator++() // prefix operator
{
    fpn;
    return ()
}

const Fixed Fixed::operator++(int) //postfix operator, using dummy int to differentiate between pre- and post-increment
{

}