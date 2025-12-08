#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "// (start of program) DEFAULT CONSTRUCTORS \n" << std::endl;
    ClapTrap a("First");
    ClapTrap b("Second");

    // test all functions
    std::cout << "\n// ClapTrap: Test public functions\n" << std::endl;
    a.attack(b.getName()); // we dont modify DamagePoints yet so it will always print 0 here
    a.takeDamage(1000);
    // First took damage so cannot attack or be repaired anymore
    a.attack(b.getName());
    a.beRepaired(20);
    // test copy constructor
    std::cout << "\n// ClapTrap: Test copy constructor && attack\n" << std::endl;
    ClapTrap c = a;
    c.attack(b.getName());
    // test assignment operator
    std::cout << "\n// ClapTrap: Test assignment operator && attack\n" << std::endl;
    ClapTrap d("Temp");
    d = b;
    d.attack(a.getName());

    // destruction
    std::cout << "\n\n// (end of program) DESTRUCTORS \n" << std::endl;
}