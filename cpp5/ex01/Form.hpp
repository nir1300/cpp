#pragma once

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        // Orthodox Canonical Form
        Form(const std::string name, const int signGrade, const int execGrade);
        Form();
        ~Form(); 
        Form(const Form &other);
        Form &operator=(const Form& other);

        // member functions
        std::string getName() const;
        bool         getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        void        beSigned(Bureaucrat buri);

        // nested exception classes
        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream &operator<<(std::ostream& out, Form form);

#endif