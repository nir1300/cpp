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
    {
    std::cout << "Test animals: \n" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    delete meta;
    delete i;
    delete j;
    }
    {
    std::cout << "\n[Cat] Test copy constructor\n" << std::endl;
    Cat aa;
    Cat bb(aa);
    std::cout << "Brain address: " << aa.getBrain() << std::endl;
    std::cout << "Brain address: " << bb.getBrain() << std::endl; // different memory address -> deep copy
    }
    {
    std::cout << "\n[Cat] Test copy assignment operator\n" << std::endl;
    Cat cc;
    Cat dd;
    dd = cc;
    }
    {
    std::cout << "\n[Dog] Test copy constructor & copy assignment operator\n" << std::endl;
    Dog aa;
    Dog bb(aa); // test copy constructor
    std::cout << "Brain address: " << aa.getBrain() << std::endl;
    std::cout << "Brain address: " << bb.getBrain() << std::endl; // different memory address -> deep copy
    Dog cc;
    Dog dd; // test copy assignment operator
    dd = cc;
    }
}