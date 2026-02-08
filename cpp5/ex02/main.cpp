#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <exception>
#include <ctime>
#include <cstdlib>

// https://cplusplus.com/doc/tutorial/exceptions/


int main(void)
{
    {
        std::cout << "<<< SHRUBBERY CREATION TESTS >>>" << std::endl;
        ShrubberyCreationForm a("Home");
        Bureaucrat b("nina", 2);
        try {
            std::cout << a;
            b.signForm(a);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        b.incrementGrade();
        try {
            b.signForm(a);
            std::cout << a;
            b.executeForm(a);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::srand(std::time(NULL)); // for random number generator
        std::cout << "\n\n<<< ROBOTOMY REQUEST TESTS >>>" << std::endl;
        RobotomyRequestForm a("Monster");
        Bureaucrat b("nina", 45);
        try {
            std::cout << a;
            b.executeForm(a);
            b.signForm(a);
            b.executeForm(a);
            std::cout << a;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\n\n<<< PRESIDENTIAL PARDON TESTS >>>" << std::endl;
        PresidentialPardonForm a("Eminem");
        Bureaucrat b("nina", 4);
        try {
            std::cout << a;
            b.executeForm(a);
            b.signForm(a);
            b.executeForm(a);
            std::cout << a;
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
}