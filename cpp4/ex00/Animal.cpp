#include "Animal.hpp"

void Animal::makeSound()
{
    ;
}


Animal::Animal(std::string InputType): type(InputType)
{
    std::cout << "The Animal constructor has been called." << std::endl;
}

Animal::~Animal()
{
    std::cout << "The Animal destructor has been called." << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{
    std::cout << "The Animal copy constructor has been called." << std::endl;

}

Animal &Animal::operator=(const Animal& other)
{
    std::cout << "The Animal copy assignment operator has been called." << std::endl;
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}