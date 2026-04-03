#include "ScalarConverter.hpp"

// use static_cast:
// implicit
// used to convert between related types (int/float): all numeric types in this ex
// compile-time checks to ensure types are compatible

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Need 1 argument for conversion" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
}