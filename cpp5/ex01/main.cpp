#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <exception>

// https://cplusplus.com/doc/tutorial/exceptions/

void bureaucratRangeTests(std::string name, int grade)
{
    try {
        Bureaucrat test(name, grade);
        std::cout << test;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void changeGradeTest(std::string name, int grade, int changeGrade)
{
    try {
        Bureaucrat test(name, grade);
        std::cout << test;
        if (changeGrade < 0)
            test.incrementGrade();
        else if (changeGrade > 0)
            test.decrementGrade();
        std::cout << test;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void formRangeTests(std::string name, const int signGrade, const int execGrade)
{
    try {
        Form test(name, signGrade, execGrade);
        std::cout << test;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

// TO DO BEFORE SUBMITTING
// maybe check if sign grade is higher than exec grade

int main(void)
{
    {
    std::cout << "Valid range tests:\n" << std::endl;
    formRangeTests("a", 2, 1);
    formRangeTests("b", 150, 75);
    formRangeTests("c", 150, 1);

    std::cout << "\n\nInvalid range tests:\n" << std::endl;
    formRangeTests("d", 77, -1);
    formRangeTests("e", 150, 0);
    formRangeTests("f", 151, 1);
    formRangeTests("f", 151, 0);
    }
    {
    std::cout << "\n\nTest form signing:\n" << std::endl;
    Bureaucrat a("a", 150);
    Form aa("Form a", 149, 1);
    try {
        std::cout << a;
        a.signForm(aa);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try {
        a.incrementGrade();
        std::cout << "<< grade was incremented >>" << std::endl;
        std::cout << a;
        aa.getSignGrade();
        a.signForm(aa);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
}