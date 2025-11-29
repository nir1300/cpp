#pragma once
#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contacts.hpp"

class PhoneBook {
    public:
        PhoneBook(void); // constructor

        void            add_contact(void);
        void            display_all_contacts(void) const ; 
        void            search_contacts(void) const ;

        std::string     enter_first(void);
        std::string     enter_last(void);
        std::string     enter_nick(void);
        std::string     enter_number(void);
        std::string     enter_secret(void);
    
    private:
        Contact cont[8];
        int     next_index;
        int     nb_contacts;
    };


#endif