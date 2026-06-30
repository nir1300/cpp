#include "easyfind.hpp"

// to do: tests, find index of printed int (has to be first occurence)
// change to print in main, return res
// test with dif containers not just vector
int main(void)
{
    {
        std::cout << "<<< Test vector of integers >>>" << std::endl;
        std::vector<int> cont;
        cont.push_back(1);
        cont.push_back(3);
        cont.push_back(2);
        cont.push_back(3);
        std::cout << *easyfind(cont, 3) << std::endl;
        try {
            std::cout << *easyfind(cont, 0) << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << *easyfind(cont, -1) << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << *easyfind(cont, 'n') << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "\n\n<<< Test list of chars >>>" << std::endl;
        std::list<char> cont;
        cont.push_back('n');
        cont.push_back('i');
        cont.push_back('e');
        cont.push_back('i');
        cont.push_back('/');
        try {
            std::list<char>::iterator it = easyfind(cont, 'i');
            std::cout << "Test it returns first occurence of 'i': " << *it;
            it++;
            std::cout << ", char after 'i': " << *it << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << *easyfind(cont, 'e') << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << *easyfind(cont, -1) << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        try {
            std::cout << *easyfind(cont, 'n') << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}