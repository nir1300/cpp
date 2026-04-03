#include "Serializer.hpp"
#include "Data.hpp"

// use reinterpret_cast:
// just takes memory address as raw number
// used to convert pointers to unrelated types (void* to int*)
// no safety checks -> for low-level data manipulation
// use when there is no logical relationship
// map one bit pattern to another

// when useful? -> send data over a network, many old libraries pass data as void* or integers -> reinterpret_cast bridges the gap

int main()
{
    Data* a = new Data();
    a->name = "Dave";
    a->age = 80;
    a->isAlive = false;

    // unsigned int type, guaranteed to be large enough for pointer
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