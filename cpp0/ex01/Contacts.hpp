#pragma once
#ifndef __CONTACTS_H__
#define __CONTACTS_H__

#include <iostream>
#include <bits/stdc++.h>

bool    str_isalpha(std::string str);
bool    str_isdigit(std::string str);

class Contact {
    public:
        void                  display_contact() const; // display selected contact in SEARCH

        // getters
        const std::string&    get_firstname(void) const;
        const std::string&    get_lastname(void) const;
        const std::string&    get_nickname(void) const;

        // setters 
        void    set_firstname(std::string);
        void    set_lastname(std::string);
        void    set_nickname(std::string);
        void    set_number(std::string);
        void    set_secret(std::string);

        void    format_and_print(const std::string &field) const;

    private:
        std::string first;
        std::string last;
        std::string nickname;
        std::string number;
        std::string secret;
    };

#endif