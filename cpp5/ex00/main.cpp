#include "Bureaucrat.hpp"
#include <exception>

// https://cplusplus.com/doc/tutorial/exceptions/

void rangeTests(std::string name, int grade)
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

int main(void)
{
    std::cout << "Valid range tests:\n" << std::endl;
    rangeTests("a", 1);
    rangeTests("b", 75);
    rangeTests("c", 150);

    std::cout << "\n\nInvalid range tests:\n" << std::endl;
    rangeTests("d", -1);
    rangeTests("e", 0);
    rangeTests("f", 151);

    std::cout << "\n\nValid grade in-/decrement tests:\n" << std::endl;
    changeGradeTest("g", 1, 1); // decrement grade (+1)
    changeGradeTest("h", 150, -1); // increment grade (-1)

    std::cout << "\n\nInvalid grade in-/decrement tests:\n" << std::endl;
    changeGradeTest("i", 1, -1);
    changeGradeTest("j", 150, 1); 

    try {
        Bureaucrat a("a", 3);
        std::cout << a;
        Bureaucrat b("b", 160);
        std::cout << b;
        Bureaucrat c("c", -1);
        std::cout << c;
        Bureaucrat d("d", 10);
        std::cout << d;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}