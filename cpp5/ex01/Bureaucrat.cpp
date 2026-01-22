#include "Bureaucrat.hpp"
#include "Form.hpp"

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
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat() : name("Default"), grade(150)
{
    ;
}

Bureaucrat::~Bureaucrat()
{
    ;
} 

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
    ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
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

void Bureaucrat::signForm(Form form)
{
    form.beSigned(*this);
    if (form.getIsSigned())
        std::cout << name << " signed " << form.getName() << std::endl;
    else // need to add reason!!
        std::cout << name << " couldn't sign " << form.getName() << " because grade is too low" << std::endl;
     
}