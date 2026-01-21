#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat one("Nina1", 3);
    std::cout << one;
    try {
        Bureaucrat two("Nina2", 160);
    }
    catch (std::exception &e)
    {
        std::cout << "not possible" << std::endl;
    }
}