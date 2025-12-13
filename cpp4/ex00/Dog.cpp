#include "Dog.hpp"

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

// OCF

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "[Dog] default constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "[Dog] destructor called" << std::endl;
}

Dog::Dog(const Dog &other)
{
    this->type = other.type;
    std::cout << "[Dog] copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "[Dog] assignment operator called" << std::endl;
    return (*this);
}