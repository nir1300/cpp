#pragma once
#ifndef __CONTACTS_HPP__
#define __CONTACTS_HPP__

#include <iostream>
#include <iomanip>

bool    str_isalpha(std::string str);
bool    str_isdigit(std::string str);

class Contact {
    public:
        void                  displayContact() const; // display selected contact in SEARCH

        // getters
        const std::string&    getFirstName(void) const;
        const std::string&    getLastName(void) const;
        const std::string&    getNickName(void) const;

        // setters 
        void    setFirstName(std::string);
        void    setLastName(std::string);
        void    setNickName(std::string);
        void    setNumber(std::string);
        void    setSecret(std::string);

        void    formatAndPrint(const std::string &field) const;

    private:
        std::string first;
        std::string last;
        std::string nickname;
        std::string number;
        std::string secret;
    };

#endif