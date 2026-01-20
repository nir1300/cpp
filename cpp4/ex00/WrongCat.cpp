#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

// OCF

WrongCat::WrongCat() : WrongAnimal()
{
    type = "WrongCat";
    std::cout << "[WrongCat] default constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "[WrongCat] destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    this->type = other.type;
    std::cout << "[WrongCat] copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& other)
{
    if (this != &other)
        this->type = other.type;
    std::cout << "[WrongCat] assignment operator called" << std::endl;
    return (*this);
}
