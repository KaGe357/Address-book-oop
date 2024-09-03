#ifndef CONTACTFILE_H
#define CONTACTFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Contact.h"
#include "AdditionalMethods.h"

using namespace std;
class ContactFile
{
private:

    const  string CONTACTS_DATA_FILENAME;
    int lastUsedId = 0;

    int extractContactId(const string& contactData) const;
    Contact parseContactData(const string& contactData) const;
    string formatContactData(const Contact& contact) const;
    bool isFileEmpty(ifstream& file) const;
    bool isFileEmpty(ofstream& file) const;

public:
    explicit ContactFile(const string& fileName, int lastUsedContactId) : CONTACTS_DATA_FILENAME(fileName), lastUsedId(lastUsedContactId) {};
    vector<Contact> loadContactsForUser(int userId);
    bool appendContactToFile(const Contact& contact);
    int getLastUsedId() const;
};

// ContactFile methods



#endif // CONTACTFILE_H
