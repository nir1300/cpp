#include "Dog.hpp"
#include "Animal.hpp"

void Dog::makeSound() const
{
    std::cout << "Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}

// OCF

Dog::Dog() : Animal()
{
    this->type = "Dog";
    brain = new Brain();
    std::cout << "[Dog] default constructor called" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "[Dog] destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << "[Dog] copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog& other)
{
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << "[Dog] assignment operator called" << std::endl;
    return (*this);
}