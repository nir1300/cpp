#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// deep cpy vs shallow cpy:
// if variable of object dynamically allocated -> deep copy necessary
// shallow: default copy/overload assignment operator
// deep: explicitely define copy constructor, assign dynamic memory for vars if required

int main()
{
    // Dog basic;
    // {
    // Dog tmp = basic;
    // std::cout << "Brain address: " << tmp.getBrain() << std::endl;

    // }
    // basic.getBrain();
    // std::cout << "Brain address: " << basic.getBrain() << std::endl;
    {
        std::cout << "\nCreate array as requested in subject: \n" << std::endl;

        const Animal* arr[6];
        for (int i = 0; i < 3; i++)
        {
            arr[i] = new Dog();
        }
        for (int i = 3; i < 6; i++)
        {
            arr[i] = new Cat();
        }
        for (int i = 0; i < 6; i++)
            delete arr[i];
    }
    {
        std::cout << "\n\nTest animals: \n" << std::endl;
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        std::cout << j->getType() << " " << std::endl;
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
        std::cout << "Brain address: " << aa.getBrain() << std::endl;
        std::cout << "Brain address: " << bb.getBrain() << std::endl; // different memory address -> deep copy
    
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
        std::cout << "Brain address: " << cc.getBrain() << std::endl;
        std::cout << "Brain address: " << dd.getBrain() << std::endl;

    }
}