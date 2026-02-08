#pragma once

#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm {
    private:
        const std::string name;
        bool isSigned;
        const int signGrade;
        const int execGrade;
    public:
        AForm(const std::string name, const int signGrade, const int execGrade);
        AForm();
        virtual ~AForm(); 
        AForm(const AForm &other);
        AForm &operator=(const AForm& other);

        // member functions
        std::string getName() const;
        bool         getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        void        beSigned(Bureaucrat& buri);
        void execute (Bureaucrat const & executor) const;
        virtual void execution() const = 0;

        // nested exception classes
        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class FormNotSignedException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

std::ostream &operator<<(std::ostream& out, const AForm &form);

#endif