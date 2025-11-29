#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->next_index = 0;
    this->nb_contacts = 0;
}

void PhoneBook::search_contacts(void) const
{
    std::string input;
    int index = -1;

    if (this->nb_contacts == 0)
        return ;
    std::cout << "Enter contact index: ";
    std::getline(std::cin, input);
    if (input.size() == 1 && std::isdigit((int)input[0]))
        index = input[0] - '0';
    else
        std::cout << "Invalid input (must be a single number)" << std::endl;
    if (index >= this->nb_contacts || index > 7 || index < 0)
    {
        std::cout << "Index out of range (accepted range: 0-" << this->nb_contacts - 1 << ")" << std::endl;
        return ;
    }
    else
        cont[index].display_contact();
}

void PhoneBook::display_all_contacts(void) const
{
    if (this->nb_contacts == 0)
    {
        std::cout << "No contacts in phonebook" << std::endl;
        return ;
    }
    for (int i = 0; i < this->nb_contacts; i++)
    {
        cont[i].format_and_print(cont[i].get_firstname());
        std::cout << "|";
        cont[i].format_and_print(cont[i].get_lastname());
        std::cout << "|";
        cont[i].format_and_print(cont[i].get_nickname());
        std::cout << std::endl;
    }
}



std::string    PhoneBook::enter_first(void)
{
    std::string first;
    while (1 && std::cin)
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, first);
        if (!first.empty() && str_isalpha(first))
            break;
    }
    return (first);
}

std::string    PhoneBook::enter_last(void)
{
    std::string last;
    while (1 && std::cin)
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, last);
        if (!last.empty() && str_isalpha(last))
            break;
    }
    return (last);
}

std::string    PhoneBook::enter_nick(void)
{
    std::string nick;
    while (1 && std::cin)
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nick);
        if (!nick.empty() && str_isalpha(nick))
            break;
    }
    return (nick);
}

std::string    PhoneBook::enter_number(void)
{
    std::string number;
    while (1 && std::cin)
    {
        std::cout << "Enter number: ";
        std::getline(std::cin, number);
        if (!number.empty() && str_isdigit(number))
            break;
    }
    return (number);
}

std::string    PhoneBook::enter_secret(void)
{
    std::string secret;
    while (1 && std::cin)
    {
        std::cout << "Enter secret: ";
        std::getline(std::cin, secret);
        if (!secret.empty())
            break;
    }
    return (secret);
}


void PhoneBook::add_contact()
{
    std::string first;
    std::string last;
    std::string nickname;
    std::string secret;
    std::string number;

    if (this->next_index == 8)
        this->next_index = 0;

    first = enter_first();
    last = enter_last();
    nickname = enter_nick();
    number = enter_number();
    secret = enter_secret();

    cont[next_index].set_firstname(first);
    cont[next_index].set_lastname(last);
    cont[next_index].set_nickname(nickname);
    cont[next_index].set_number(number);
    cont[next_index].set_secret(secret);

    this->next_index++;
    if (this->nb_contacts < 8)
        this->nb_contacts++;
}

int main(void)
{
    class PhoneBook pb;
    int i = 0;
    std::string cmd;
    while (1 && std::cin)
    {
        std::cout << "Enter command: ";
        std::getline(std::cin, cmd);
        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD")
            pb.add_contact();
        else if (cmd == "SEARCH")
        {
            pb.display_all_contacts();
            pb.search_contacts();
        }
        i++;
    }
}
