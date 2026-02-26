#include "easyfind.hpp"

int main(void)
{
    std::vector<int> cont;
    cont.push_back(1);
    cont.push_back(3);
    cont.push_back(2);
    easyfind(cont, 3);
    try {
        easyfind(cont, 0);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        easyfind(cont, -1);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        easyfind(cont, 'n');
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}