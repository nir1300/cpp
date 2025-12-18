#include "Contacts.hpp"

void    Contact::formatAndPrint(const std::string &field) const
{
    std::string s;
    if (field.size() > 10)
        s = field.substr(0, 9) + ".";
    else
        s = field;
    std::cout << std::setw(10) << s;
}

const std::string&    Contact::getFirstName() const
{
    return (this->first);
}

const std::string&    Contact::getLastName() const
{
    return (this->last);
}

const std::string&    Contact::getNickName() const
{
    return (this->nickname);
}

void Contact::displayContact(void) const
{
    std::cout << "First name: " << this->first << std::endl;
    std::cout << "Last name: " << this->last << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone number: " << this->number << std::endl;
    std::cout << "Secret: " << this->secret << std::endl;
}

void Contact::setFirstName(std::string str)
{
    this->first = str;
}

void Contact::setLastName(std::string str)
{
    this->last = str;
}

void Contact::setNickName(std::string str)
{
    this->nickname = str;
}

void Contact::setNumber(std::string str)
{
    this->number = str;
}

void Contact::setSecret(std::string str)
{
    this->secret = str;
}
