#include "Bureaucrat.hpp"

std::ostream &operator<<(std::ostream& out, Bureaucrat buri)
{
    return out << buri.getName() << ", bureaucrat grade " << buri.getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name)
{
    if (grade < 0)
        throw "Bureaucrat::GradeTooHighException";
    if (grade > 150)
        throw "Bureaucrat::GradeTooLowException";
    this->grade = grade;
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
    if (grade > 0)
        grade--;
    else
        throw "Bureaucrat::GradeTooHighException";
}

void Bureaucrat::decrementGrade()
{
    if (grade < 150)
        grade++;
    else
        throw "Bureaucrat::GradeTooLowException";
}

