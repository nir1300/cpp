#include "ShrubberyCreationForm.hpp"
#include <string>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "[ShrubberyCreationForm] constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
    std::cout << "[ShrubberyCreationForm] default constructor called (default values added)." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "[ShrubberyCreationForm] destructor called." << std::endl;
} 

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    this->target = other.target;
    std::cout << "[ShrubberyCreationForm] copy constructor called." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    std::cout << "[ShrubberyCreationForm] copy assignment operator called." << std::endl;
    if (this == &other)
        return *this;
    this->target = other.target;
    AForm::operator=(other); // everything else const so cant be changed
    return *this;
}

void ShrubberyCreationForm::execution(void) const
{
    std::ofstream newFile(target + "_shrubbery");

    newFile << "   /\\\n";
    newFile << "  /**\\\n";
    newFile << " /****\\\n";
    newFile << "   ||\n";

    newFile.close();
}
