#ifndef CONTACTFILE_H
#define CONTACTFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Contact.h"
#include "AdditionalMethods.h"
#include "TextFile.h"

using namespace std;
class ContactFile : public TextFile
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
explicit ContactFile(const string& fileName, int lastUsedContactId)
    : TextFile(fileName),
      CONTACTS_DATA_FILENAME(fileName),
      lastUsedId(lastUsedContactId)
{}

    vector<Contact> loadContactsForUser(int userId);
    bool appendContactToFile(const Contact& contact);
    int getLastUsedId() const;
    void updateContactInFile(const vector<Contact>& contacts, int editedContactId);
};

// ContactFile methods



#endif // CONTACTFILE_H
