#include "Bureaucrat.hpp"

const char*  Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char*  Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::ostream &operator<<(std::ostream& out, Bureaucrat buri)
{
    return out << buri.getName() << ", bureaucrat grade " << buri.getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    std::cout << "[Bureaucrat] constructor called." << std::endl;
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    std::cout << "[Bureaucrat] default constructor called (default values added)." << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "[Bureaucrat] destructor called." << std::endl;
} 

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    std::cout << "[Bureaucrat] copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << "[Bureaucrat] copy assignment operator called." << std::endl;
    if (this == &other)
        return *this;
    this->grade = other.grade;
    return *this;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade > 1)
        grade--;
    else
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    if (grade < 150)
        grade++;
    else
        throw GradeTooLowException();
}
