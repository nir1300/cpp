#include <iostream>

int main(void)
{
    std::string txt = "HI THIS IS BRAIN";
    std::string *stringPTR = &txt;
    std::string &stringREF = txt;

    std::cout << &txt << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << txt << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;

}