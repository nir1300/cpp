#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
    this->nextIndex = 0;
    this->nbContacts = 0;
}

void PhoneBook::searchContacts(void) const
{
    std::string input;
    int index = -1;

    if (this->nbContacts == 0)
        return ;
    while (1 && std::cin)
    {
        std::cout << "Enter contact index: ";
        std::getline(std::cin, input);
        if (input.empty())
            continue;
        if (input.size() == 1 && std::isdigit((int)input[0]))
        {
            index = input[0] - '0';
            if (index >= this->nbContacts || index > 7 || index < 0)
                std::cout << "Index out of range (accepted range: 0-" << this->nbContacts - 1 << "). Try again." << std::endl;
            else
            {
                cont[index].displayContact();
                break;
            }
        }
        else
            std::cout << "Invalid input (must be a single number, accepted range: 0-" << this->nbContacts - 1 << "). Try again." << std::endl;
    }
    // cont[index].displayContact();
}

void PhoneBook::displayAllContacts(void) const
{
    if (this->nbContacts == 0)
    {
        std::cout << "No contacts in phonebook" << std::endl;
        return ;
    }

    for (int i = 0; i < this->nbContacts; i++)
    {
        std::cout << std::setw(10) << i;
        std::cout << "|";
        cont[i].formatAndPrint(cont[i].getFirstName());
        std::cout << "|";
        cont[i].formatAndPrint(cont[i].getLastName());
        std::cout << "|";
        cont[i].formatAndPrint(cont[i].getNickName());
        std::cout << std::endl;
    }
}



std::string    PhoneBook::enterFirst(void)
{
    std::string first;
    while (1 && std::cin)
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, first);
        if (first.empty())
            continue;
        if (!first.empty() && str_isalpha(first))
            break;
        std::cout << "Field cannot be empty. Only letters a-z/A-Z are accepted. Try again." << std::endl;
    }
    return (first);
}

std::string    PhoneBook::enterLast(void)
{
    std::string last;
    while (1 && std::cin)
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, last);
        if (last.empty())
            continue;
        if (!last.empty() && str_isalpha(last))
            break;
        std::cout << "Field cannot be empty. Only letters a-z/A-Z are accepted. Try again." << std::endl;
    }
    return (last);
}

std::string    PhoneBook::enterNick(void)
{
    std::string nick;
    while (1 && std::cin)
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, nick);
        if (nick.empty())
            continue;
        if (!nick.empty() && str_isalpha(nick))
            break;
        std::cout << "Field cannot be empty. Only letters a-z/A-Z are accepted. Try again." << std::endl;
    }
    return (nick);
}

std::string    PhoneBook::enterNumber(void)
{
    std::string number;
    while (1 && std::cin)
    {
        std::cout << "Enter number: ";
        std::getline(std::cin, number);
        if (number.empty())
            continue;
        if (!number.empty() && str_isdigit(number))
            break;
        std::cout << "Field cannot be empty. Only numbers 0-9 are accepted. Try again." << std::endl;
    }
    return (number);
}

std::string    PhoneBook::enterSecret(void)
{
    std::string secret;
    while (1 && std::cin)
    {
        std::cout << "Enter secret: ";
        std::getline(std::cin, secret);
        if (secret.empty())
            continue;
        if (!secret.empty())
            break;
        std::cout << "Field cannot be empty." << std::endl;
    }
    return (secret);
}


void PhoneBook::addContact()
{
    std::string first;
    std::string last;
    std::string nickname;
    std::string secret;
    std::string number;

    if (this->nextIndex == 8)
        this->nextIndex = 0;

    first = enterFirst();
    last = enterLast();
    nickname = enterNick();
    number = enterNumber();
    secret = enterSecret();

    cont[nextIndex].setFirstName(first);
    cont[nextIndex].setLastName(last);
    cont[nextIndex].setNickName(nickname);
    cont[nextIndex].setNumber(number);
    cont[nextIndex].setSecret(secret);

    this->nextIndex++;
    if (this->nbContacts < 8)
        this->nbContacts++;
}


