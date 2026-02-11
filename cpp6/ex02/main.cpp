#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
    std::srand(std::time(NULL)); // for random number generator
    Base *test = generate();
    identify(test);
    identify(*test);
    delete test;
}