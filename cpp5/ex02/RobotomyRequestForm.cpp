#include "RobotomyRequestForm.hpp"
#include <string>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "[RobotomyRequestForm] constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Default")
{
    std::cout << "[RobotomyRequestForm] default constructor called (default values added)." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "[RobotomyRequestForm] destructor called." << std::endl;
} 

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    this->target = other.target;
    std::cout << "[RobotomyRequestForm] copy constructor called." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << "[RobotomyRequestForm] copy assignment operator called." << std::endl;
    if (this == &other)
        return *this;
    this->target = other.target;
    AForm::operator=(other); // everything else const so cant be changed
    return *this;
}

#include <cstdlib>

void RobotomyRequestForm::execution(void) const
{
    int success = std::rand() % 2;
    if (success)
        std::cout << target << " has been robotomized successfully (50% chance)." << std::endl;
    else
        std::cout << "Robotomy for target '"<< target << "' has failed (50% chance)." << std::endl;
}
