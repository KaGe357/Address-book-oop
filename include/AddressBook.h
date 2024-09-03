#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include "ContactManager.h"


using namespace std;

class AddressBook
{

    ContactManager *contactManager;
    const string CONTACT_DATA_FILENAME;
    int loggedId;


public:
    UserManager userManager;
    AddressBook(string userDataFilename, string contactDataFilename)
    : userManager(userDataFilename), CONTACT_DATA_FILENAME(contactDataFilename)
    {
        contactManager= NULL ;
    };

    ~AddressBook()
    {
        delete contactManager;
        contactManager = NULL;
    }
    void registerNewUser();
    void printAllUsers();
    void printAllContacts();
    void registerNewContact();
    int loggedUserId;
    int loginUser();
    void logoutUser();
    void printMainMenu();
    void printLoggedUserMenu();

};
#endif
