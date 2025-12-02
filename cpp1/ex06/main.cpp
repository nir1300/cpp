#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cout << "Invalid argument number" << std::endl, 1);
    Harl test;
    test.complain((std::string)argv[1]);
    // std::cout << std::endl;
    // test.complain("INFO");
    // std::cout << std::endl;
    // test.complain("WARNING");
    // std::cout << std::endl;
    // test.complain("ERROR");
    // std::cout << std::endl;
    // test.complain("nonsense");

}