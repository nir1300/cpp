#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("First");
    ClapTrap b("Second");
    a.attack(b.getName()); // we dont modify DamagePoints yet so it will always print 0 here
    a.takeDamage(1000);
    // First took damage so cannot attack or be repaired anymore
    a.attack(b.getName());
    a.beRepaired(20);
    // test copy constructor
    ClapTrap c = a;
    // test assignment operator
    ClapTrap d("Temp");
    d = b;
    d.attack(a.getName());
}