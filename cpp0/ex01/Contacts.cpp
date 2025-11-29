#include "Contacts.hpp"

void    Contact::format_and_print(const std::string &field) const
{
    std::string s;
    if (field.size() >= 10)
        s = field.substr(0, 9) + ".";
    else
        s = field;
    std::cout << std::setw(10) << s;
}

const std::string&    Contact::get_firstname() const
{
    return (this->first);
}

const std::string&    Contact::get_lastname() const
{
    return (this->last);
}

const std::string&    Contact::get_nickname() const
{
    return (this->nickname);
}

void Contact::display_contact(void) const
{
    std::cout << "First name: " << this->first << std::endl;
    std::cout << "Last name: " << this->last << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone number: " << this->number << std::endl;
    std::cout << "Secret: " << this->secret << std::endl;
}

void Contact::set_firstname(std::string str)
{
    this->first = str;
}

void Contact::set_lastname(std::string str)
{
    this->last = str;
}

void Contact::set_nickname(std::string str)
{
    this->nickname = str;
}

void Contact::set_number(std::string str)
{
    this->number = str;
}

void Contact::set_secret(std::string str)
{
    this->secret = str;
}
