#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H
#include <iostream>
#include <fstream>
#include "ContactFile.h"
#include "Contact.h"
#include "AdditionalMethods.h"


using namespace std;

class ContactManager
{
    int loggedUserId;
    const int LOGGED_USER_ID;
    int lastUsedId;
    vector<Contact>contacts;
    ContactFile contactFile;


    Contact giveNewUserId();
    int getNewUserId();
    Contact giveNewContactData();
    void printContactData(Contact contact);

public:
    ContactManager(string contactFileName, int loggedUserId) : contactFile(contactFileName, contactFile.getLastUsedId()), LOGGED_USER_ID(loggedUserId)
    {
        contacts = contactFile.loadContactsForUser(LOGGED_USER_ID);
    }
    void registerNewContact();
    void printAllContacts();
   // int loadContactsForUser(int loggedUserId);
    //void setLoggedUserId(int newId);
    int getLoggedUserId();



};

#endif // CONTACTMANAGER_H



