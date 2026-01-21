#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

// abstract class: class designed to be a base class
// a class that defines or inherits at last one pure virtual function
// declare pure virtual function by using pure specifier = =
int main()
{
    {
    // // Animal can no longer be instantiated -> will throw compiler error
    // Animal test;
    std::cout << "Test animals: \n" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
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