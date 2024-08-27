#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include "ContactManager.h"


using namespace std;

class AddressBook
{
    UserManager userManager;
    ContactManager contactManager;


public:
    AddressBook();
    void registerNewUser();
    void printAllUsers();
    void printAllContacts();
    void registerNewContact();
    int loggedUserId;
    int loginUser();


};
#endif
