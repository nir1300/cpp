#include "PresidentialPardonForm.hpp"
#include <string>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "[PresidentialPardonForm] constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Default")
{
    std::cout << "[PresidentialPardonForm] default constructor called (default values added)." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "[PresidentialPardonForm] destructor called." << std::endl;
} 

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    this->target = other.target;
    std::cout << "[PresidentialPardonForm] copy constructor called." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << "[PresidentialPardonForm] copy assignment operator called." << std::endl;
    if (this == &other)
        return *this;
    this->target = other.target;
    AForm::operator=(other); // everything else const so cant be changed
    return *this;
}

#include <cstdlib>

void PresidentialPardonForm::execution(void) const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
