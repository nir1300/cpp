#include "Zombie.hpp"

int main(void)
{
    int size = 3;
    Zombie *horde = zombieHorde(size, "Horde");
    for (int i = 0; i < size; i++)
        horde[i].announce();
    delete[] horde;
}