#include "ContactFile.h"

using namespace std;
int ContactFile::getLastUsedId() const
{
    return lastUsedId;
}

void ContactFile::appendContactToFile(const Contact& contact)
{
    ifstream fileCheck(contactsDataFileName);  // U¿ycie ifstream do sprawdzenia pustego pliku
    ofstream textFile(contactsDataFileName, ios::out | ios::app);

    if (textFile)
    {
        if (isFileEmpty(fileCheck))    // Sprawdzenie pustego pliku
        {
            textFile << formatContactData(contact);
        }
        else
        {
            textFile << "\n" << formatContactData(contact);
        }
    }
    else
    {
        cerr << "Nie udalo sie otworzyc pliku do zapisu.\n";
    }
}

vector<Contact> ContactFile::loadContactsForUser(int userId)
{
    ifstream textFile(contactsDataFileName);
    vector<Contact> userContacts;
    Contact contact;
    int maxId = 0;

    if (textFile)
    {
        string line;
        while (getline(textFile, line))
        {
            contact = parseContactData(line);
            if (extractContactId(line) == userId)
            {
                userContacts.push_back(contact);
            }
            if (contact.getId() > maxId)
            {
                maxId = contact.getId();
            }
        }
        lastUsedId = maxId;
    }
    else
    {
        cerr << "Nie udalo sie otworzyc pliku\n";
    }

    return userContacts;
}


// helper methods

int ContactFile::extractContactId(const string& contactData) const
{
    istringstream stream(contactData);
    string idStr;
    getline(stream, idStr, '|');
    return std::stoi(idStr);
}

Contact ContactFile::parseContactData(const string& contactData) const
{
    istringstream stream(contactData);
    string idStr, userIdStr, name, lastName, phoneNumber, email, homeAddress;

    getline(stream, idStr, '|');
    getline(stream, userIdStr, '|');
    getline(stream, name, '|');
    getline(stream, lastName, '|');
    getline(stream, phoneNumber, '|');
    getline(stream, email, '|');
    getline(stream, homeAddress, '|');

    int id = stoi(idStr);
    int userId = stoi(userIdStr);

    return Contact(id, userId, name, lastName, phoneNumber, email, homeAddress);
}

string ContactFile::formatContactData(const Contact& contact) const
{
    ostringstream stream;
    stream << contact.getId() << "|" << contact.getUserId() << "|"<< contact.getName() << "|"<< contact.getLastName() << "|" << contact.getPhoneNum()
           << contact.getEmail() << "|"<< contact.getHomeAddress() << "|";
    return stream.str();
}


bool ContactFile::isFileEmpty(ifstream& file) const
{
    return file.peek() == ifstream::traits_type::eof();
}

bool ContactFile::isFileEmpty(ofstream& file) const
{

    string filePath = contactsDataFileName;
    ifstream tempFile(filePath);
    return tempFile.peek() == ifstream::traits_type::eof();
}
