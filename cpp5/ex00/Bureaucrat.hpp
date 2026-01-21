#pragma once

#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <exception>

class Bureaucrat {
    protected:
        const std::string name; // should be const
        int grade;
    public:
        Bureaucrat(std::string const name, int grade);
        std::string getName() const;
        int getGrade() const;
        void    incrementGrade();
        void    decrementGrade();
        GradeTooHighException
    
};

std::ostream &operator<<(std::ostream& out, Bureaucrat buri);

#endif