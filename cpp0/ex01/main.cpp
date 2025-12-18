#include "PhoneBook.hpp"
#include "Contacts.hpp"

int main(void)
{
    class PhoneBook pb;
    std::string cmd;
    while (1 && std::cin)
    {
        std::cout << "Enter command (ADD, SEARCH or EXIT): ";
        std::getline(std::cin, cmd);
        if (cmd.empty())
            continue ;
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD")
            pb.addContact();
        else if (cmd == "SEARCH")
        {
            pb.displayAllContacts();
            pb.searchContacts();
        }
    }
}