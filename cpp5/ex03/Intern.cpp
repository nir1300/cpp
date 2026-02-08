#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern()
{
    std::cout << "[Intern] constructor called." << std::endl;
}

Intern::~Intern()
{
    std::cout << "[Intern] destructor called." << std::endl;
} 

Intern::Intern(const Intern &other)
{
    std::cout << "[Intern] copy constructor called." << std::endl;
}

Intern &Intern::operator=(const Intern& other)
{
    std::cout << "[Intern] copy assignment operator called." << std::endl;
    // if (this == &other)
    //     return *this;
    return *this;
}

AForm* Intern::pForm(std::string target)
{
    // must return by value or reference here
    // otherwise: object slicing -> returns not PresParForm but AForm that used to be PresParForm
    return (new PresidentialPardonForm(target)); 
}

AForm* Intern::rForm(std::string target)
{
    return (new RobotomyRequestForm(target)); 
}

AForm* Intern::sForm(std::string target)
{
    return (new ShrubberyCreationForm(target)); 
}

AForm* Intern::makeForm(std::string name, std::string target)
{
    
    // check name
    // create form
    std::string forms[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm* (Intern::*actions[3])(std::string) = {&Intern::pForm, &Intern::rForm, &Intern::sForm};
    int i;
    for (i = 0; i < 3; i++)
    {
        if (name == forms[i])
            break;
    }
    switch (i)
    {
        default:
            throw FormNotExistException();
        std::cout << "Intern creates " << name << std::endl;
        case 0:
            return (this->*actions[0])(target);
            /* FALLTHROUGH */
        case 1:
            return (this->*actions[1])(target);
            /* FALLTHROUGH */
        case 2:
            return (this->*actions[2])(target);
            break;
    }
    return (NULL);
}

const char*  Intern::FormNotExistException::what() const throw()
{
    return ("Form does not exist");
}