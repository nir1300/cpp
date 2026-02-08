#pragma once

#ifndef __INTERN_HPP__
#define __INTERN_HPP__

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern {
    public:
        // Orthodox Canonical Form
        Intern();
        ~Intern(); 
        Intern(const Intern &other);
        Intern &operator=(const Intern& other);

        // member functions
        AForm* makeForm(std::string name, std::string target);

        // create Forms (pointers to member functions)
        AForm* pForm(std::string target);
        AForm* rForm(std::string target);
        AForm* sForm(std::string target);

        class FormNotExistException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

#endif