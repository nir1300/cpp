#pragma once

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <exception>


class GradeTooHighException: public std::exception {
    public:
        virtual const char* what() const throw();
};

class GradeTooLowException: public std::exception {
    public:
        virtual const char* what() const throw();
};

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        // Orthodox Canonical Form
        Bureaucrat(std::string const name, int grade);
        Bureaucrat();
        ~Bureaucrat(); 
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat& other);

        // member functions
        std::string getName() const;
        int getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
};

std::ostream &operator<<(std::ostream& out, Bureaucrat buri);

#endif