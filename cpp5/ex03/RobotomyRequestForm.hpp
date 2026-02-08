#pragma once

#ifndef __ROBOTOMYREQUESTFORM_HPP__
#define __ROBOTOMYREQUESTFORM_HPP__

#include <iostream>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string target;
    public:
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm();
        ~RobotomyRequestForm(); 
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm& other);

        void execution(void) const;
};

#endif