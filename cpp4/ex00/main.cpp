#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "Test animals: \n" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    Cat aa;
    Cat bb(aa); // test copy constructor
    Cat cc;
    Cat dd; // test copy assignment operator
    dd = cc;

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << bb.getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout << "\n\nTest wrong animals: \n" << std::endl;
    const WrongAnimal* a = new WrongAnimal();
    const WrongAnimal* c = new WrongCat();
    std::cout << a->getType() << " " << std::endl;
    std::cout << c->getType() << " " << std::endl;
    a->makeSound(); // will output the wrong animal sound!
    c->makeSound(); // same

    delete meta;
    delete i;
    delete j;
    delete a;
    delete c;

    return 0;
}