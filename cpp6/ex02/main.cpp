#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// dynamic cast:
// cast happens at runtime (RTTI = runtime type information)
// specifically for handling polymorphism
// for downcasting (=converting base pointer/referenced to derived one) 

int main()
{
    std::srand(std::time(NULL)); // for random number generator
    Base *test = generate(); // polymorphism: points to A, B or C
    identify(test); // takes pointer -> prin
    identify(*test);
    delete test;
}