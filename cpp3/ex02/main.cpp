#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "// FRAGTRAP TESTS\n" << std::endl;
    std::cout << "// (start of program) DEFAULT CONSTRUCTORS -> first ClapTrap, then FragTrap\n" << std::endl;
    FragTrap a("First");
    FragTrap b("Second");
    std::cout << "\n// CLAPTRAP TESTS: Test base class functions\n" << std::endl;
    a.attack(b.getName()); // will print ClapTrap since we didnt have to modify this function
    a.takeDamage(1000); // same
    a.attack(b.getName()); // same
    a.beRepaired(20); // same

    // test copy constructor && attack
    FragTrap e("Fraggy1");
    std::cout << "\n// FragTrap: Test copy constructor\n" << std::endl;
    FragTrap f = e;
    f.attack(e.getName());

    // test assignment operator && attack
    std::cout << "\n// FragTrap: Test assignment operator\n" << std::endl;
    FragTrap g("Fraggy2");
    g = e;
    g.attack(f.getName());

    // test new function
    std::cout << "\n// FragTrap: Test high five\n" << std::endl;
    g.highFivesGuys();
    // destruction
    std::cout << "\n// (end of program) DESTRUCTORS  -> first FragTrap, then ClapTrap\n" << std::endl;
}