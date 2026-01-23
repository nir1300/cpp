#include "AForm.hpp"

std::ostream &operator<<(std::ostream& out, Form form)
{
    return out << "form name: " << form.getName() << ", signed: " << form.getIsSigned() << ", sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecGrade() << std::endl;
}

const char*  Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char*  Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

Form::Form(const std::string name, const int signGrade, const int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    std::cout << "[Form] constructor called." << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    // isSigned = false;
}

Form::Form() : name("Default"), isSigned(false), signGrade(100), execGrade(10)
{
    std::cout << "[Form] default constructor called (default values added)." << std::endl;
}

Form::~Form()
{
    std::cout << "[Form] destructor called." << std::endl;
} 

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
    std::cout << "[Form] copy constructor called." << std::endl;
}

Form &Form::operator=(const Form& other)
{
    std::cout << "[Form] copy assignment operator called." << std::endl;
    if (this == &other)
        return *this;
    isSigned = other.isSigned; // everything else const so cant be changed
    return *this;
}

std::string Form::getName() const
{
    return name;
}

bool         Form::getIsSigned() const
{
    return isSigned;
}

int         Form::getSignGrade() const
{
    return signGrade;
}

int         Form::getExecGrade() const
{
    return execGrade;
}

void        Form::beSigned(Bureaucrat buri)
{
    if (buri.getGrade() > getSignGrade())
        throw GradeTooLowException();
    isSigned = true;
}


