#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    std::cout << "// SCAVTRAP TESTS\n" << std::endl;
    std::cout << "\n// (start of program) DEFAULT CONSTRUCTORS \n" << std::endl;

    ScavTrap a("First");
    ScavTrap b("Second");
    std::cout << "\n// Test base class functions\n" << std::endl;
    a.attack(b.getName());
    a.takeDamage(1000); // will print ClapTrap since we didnt have to modify this function
    a.attack(b.getName());
    a.beRepaired(20); // will print ClapTrap since we didnt have to modify this function



    ScavTrap e("Scavvy1");

    // test copy constructor && attack
    std::cout << "\n// ScavTrap: Test copy constructor\n" << std::endl;
    ScavTrap f = e;
    f.attack(e.getName());

    // test assignment operator && attack
    std::cout << "\n// ScavTrap: Test assignment operator\n" << std::endl;
    ScavTrap g("Scavvy2");
    g = e;
    g.attack(f.getName());

    // destruction
    std::cout << "\n\n// (end of program) DESTRUCTORS \n" << std::endl;
}