#include "AForm.hpp"

std::ostream &operator<<(std::ostream& out, const AForm &aform)
{
    return out << "AForm name: " << aform.getName() << ", signed: " << aform.getIsSigned() << ", sign grade: " << aform.getSignGrade() << ", execution grade: " << aform.getExecGrade() << std::endl;
}

const char*  AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char*  AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

AForm::AForm(const std::string name, const int signGrade, const int execGrade) : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade)
{
    std::cout << "[AForm] constructor called." << std::endl;
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
    // isSigned = false;
}

AForm::AForm() : name("Default"), isSigned(false), signGrade(100), execGrade(10)
{
    std::cout << "[AForm] default constructor called (default values added)." << std::endl;
}

AForm::~AForm()
{
    std::cout << "[AForm] destructor called." << std::endl;
} 

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade)
{
    std::cout << "[AForm] copy constructor called." << std::endl;
}

AForm &AForm::operator=(const AForm& other)
{
    std::cout << "[AForm] copy assignment operator called." << std::endl;
    if (this == &other)
        return *this;
    isSigned = other.isSigned; // everything else const so cant be changed
    return *this;
}

std::string AForm::getName() const
{
    return name;
}

bool         AForm::getIsSigned() const
{
    return isSigned;
}

int         AForm::getSignGrade() const
{
    return signGrade;
}

int         AForm::getExecGrade() const
{
    return execGrade;
}

void        AForm::beSigned(Bureaucrat& buri)
{
    if (buri.getGrade() > getSignGrade())
        throw GradeTooLowException();
    isSigned = true;
}

const char*  AForm::FormNotSignedException::what() const throw()
{
    return ("Grade is too low");
}

void AForm::execute (Bureaucrat const & executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > execGrade)
        throw GradeTooLowException();
    else
        execution();
}

