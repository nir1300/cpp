#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data* a = new Data();
    a->name = "Dave";
    a->age = 80;
    a->isAlive = false;

    uintptr_t b_ptr = Serializer::serialize(a);
    Data *b = Serializer::deserialize(b_ptr);

    std::cout << "original:        " << a << std::endl;
    std::cout << "(de)-serialized: " << b << std::endl;

    std::cout << "\nTest data survived:" << std::endl;
    std::cout << "Name: " << b->name << std::endl;
    std::cout << "Age: " << b->age << std::endl;
    std::cout << std::boolalpha;
    std::cout << "Is alive: " << b->isAlive << std::endl;
    // std::cout << "(de)-serialized:\n" << Serializer::deserialize(Serializer::serialize(a)) << std::endl;
    delete a;
}