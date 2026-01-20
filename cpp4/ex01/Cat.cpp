#include "Cat.hpp"

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

Brain *Cat::getBrain() const
{
    return this->brain;
}


// OCF

Cat::Cat() : Animal()
{
    type = "Cat";
    this->brain = new Brain();
    std::cout << "[Cat] default constructor called" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "[Cat] destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << "[Cat] copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
    if (this != &other)
    {
        this->type = other.type;
        delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    std::cout << "[Cat] assignment operator called" << std::endl;
    return (*this);
}
