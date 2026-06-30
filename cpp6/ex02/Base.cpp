#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <exception>

Base::~Base() {}

Base * generate(void){
    // randomly choose A, B or C
    int rando = std::rand() % 3;
    switch (rando) {
        case 0:
            std::cout << "[A] generated" << std::endl;
            return (new A());
        case 1:
            std::cout << "[B] generated" << std::endl;
            return (new B());
        case 2:
            std::cout << "[C] generated" << std::endl;
            return (new C());
        default:
            std::cout << "Error while generating A, B or C" << std::endl;
            return (NULL);
    }

}

// pointer: if dynamic_cast fails -> returns NULL, enough safety check
void identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "[Pointer input] A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "[Pointer input] B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "[Pointer input] C" << std::endl;
    else
        std::cout << "No successful conversion: neither A, B nor C" << std::endl;
}

// reference: must refer to a valid object/cant be NULL
// if cast fails: try/catch to not crash program
void identify(Base& p){
    try {
        A &aTest = dynamic_cast<A&>(p); // &aTest to avoid copying, unnecessary
        (void)aTest;
        std::cout << "[Reference input] A" << std::endl;

    }
    catch (std::exception& e) {}
    try {
        B &bTest = dynamic_cast<B&>(p);
        std::cout << "[Reference input] B" << std::endl;
        (void)bTest;
    }
    catch (std::exception& e) {}
    try {
        C &cTest = dynamic_cast<C&>(p);
        std::cout << "[Reference input] C" << std::endl;
        (void)cTest;
    }
    catch (std::exception& e) {}
}