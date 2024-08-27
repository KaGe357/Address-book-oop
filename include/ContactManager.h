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
    int lastUsedId;
    vector<Contact>contacts;
    ContactFile contactFile;
    Contact contact;


    Contact giveNewUserId();
    int getNewUserId();
    Contact giveNewContactData(int loggedUserId);
    void printContactData(Contact contact);

public:
    ContactManager();
    int registerNewContact(int loggedUserId);
    void printAllContacts();
    int loadContactsForUser(int loggedUserId);
    void setLoggedUserId(int newId);
    int getLoggedUserId();



};

#endif // CONTACTMANAGER_H



