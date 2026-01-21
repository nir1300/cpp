#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// wrong animals: is it correct (sound)?

int main()
{
    {
        std::cout << "Test animals: \n" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound();
        std::cout << j->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        std::cout << i->getType() << " " << std::endl;
        j->makeSound();

        delete meta;
        delete i;
        delete j;
    }
    {
        std::cout << "\n\nTest copy constructor\n" << std::endl;
        Cat aa;
        Cat bb(aa);
        std::cout << aa.getType() << " " << std::endl;
        aa.makeSound();
        std::cout << bb.getType() << " " << std::endl;
        bb.makeSound();
    }
    {
        std::cout << "\n\nTest copy assignment operator\n" << std::endl;
        Dog cc;
        Dog dd;
        dd = cc;
        std::cout << cc.getType() << " " << std::endl;
        cc.makeSound();
        std::cout << dd.getType() << " " << std::endl;
        dd.makeSound();
    }
    {
        std::cout << "\n\nTest wrong animals: \n" << std::endl;
        const WrongAnimal* a = new WrongAnimal();
        const WrongAnimal* c = new WrongCat();
        const WrongCat *d = new WrongCat();
        std::cout << "\nTest type/sound:" << std::endl;
        std::cout << a->getType() << " " << std::endl;
        a->makeSound(); // will output the wrong animal sound!
        std::cout << c->getType() << " " << std::endl;
        c->makeSound(); // same
        std::cout << d->getType() << " " << std::endl;
        d->makeSound();
        delete a;
        delete c;
        delete d;
    }
}