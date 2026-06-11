#include "Array.hpp"

int main( void ) {
    Array<int> test;
    try {
        const Array<int> a(10);
        a[0]; // ERROR in your current version
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        char letter = 'a';
        Array<char> a(3);
        for (int i = 0; i < 3; i++)
        {
            a[i] = letter;
            letter++;
        }
        for (int j = 0; j < 3; j++)
            std::cout << a[j];
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Array<const char *> a(3);
        a[0] = "hello ";
        a[1] = "world";
        a[2] = "!!!";
        for (int j = 0; j < 3; j++)
            std::cout << a[j];
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        Array<int> b(10);
        for (int i = 0; i <= 10; i++)
            b[i] = i;   
        for (int j = 0; j < 10; j++)
            std::cout << b[j];     
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Array<int> b(10);
        for (int i = 0; i < 10; i++)
            b[i] = i;  
        Array<int> c(b); 
        c[9] = 0;  
        std::cout << "                 Original array: ";   
        for (int j = 0; j < 10; j++)
            std::cout << b[j];
        std::cout << "\nModified copy constructed array: ";   
        for (int j = 0; j < 10; j++)
            std::cout << c[j];
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Array<int> b(10);
        for (int i = 0; i < 10; i++)
            b[i] = i;  
        Array<int> c = b; 
        c[9] = 0;  
        std::cout << "                         Original array: ";   
        for (int j = 0; j < 10; j++)
            std::cout << b[j];
        std::cout << "\nModified copy assignenet operator array: ";   
        for (int j = 0; j < 10; j++)
            std::cout << c[j];
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Array<int> empty;
        std::cout << "Empty size: " << empty.size() << std::endl;
        empty[0]; // should throw
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Array<int> a(5);
        for (int i = 0; i < 5; i++)
            std::cout << a[i] << " ";
        std::cout << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}