#include "Harl.hpp"

int main(void)
{
    Harl test;
    test.complain("DEBUG");
    std::cout << std::endl;
    test.complain("INFO");
    std::cout << std::endl;
    test.complain("WARNING");
    std::cout << std::endl;
    test.complain("ERROR");
    std::cout << std::endl;
    test.complain("nonsense");

}