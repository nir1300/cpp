#pragma once
#ifndef __PHONEBOOK_HPP__
#define __PHONEBOOK_HPP__

#include "Contacts.hpp"
#include <iostream>
#include <bits/stdc++.h>

class PhoneBook {
    public:
        PhoneBook(void); // constructor

        void            addContact(void);
        void            displayAllContacts(void) const ; 
        void            searchContacts(void) const ;

        std::string     enterFirst(void);
        std::string     enterLast(void);
        std::string     enterNick(void);
        std::string     enterNumber(void);
        std::string     enterSecret(void);
    
    private:
        Contact cont[8];
        int     nextIndex;
        int     nbContacts;
    };


#endif