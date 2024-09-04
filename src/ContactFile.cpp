#include "ContactFile.h"

using namespace std;
int ContactFile::getLastUsedId() const
{
    return lastUsedId;
}

bool ContactFile::appendContactToFile(const Contact& contact)
{
    ifstream fileCheck(CONTACTS_DATA_FILENAME);  // Uzycie ifstream do sprawdzenia pustego pliku
    ofstream textFile(CONTACTS_DATA_FILENAME, ios::out | ios::app);

    if (textFile)
    {
        if (TextFile::isFileEmpty(fileCheck))
        {
            textFile << formatContactData(contact);
            lastUsedId++;
        }
        else
        {
            textFile << "\n" << formatContactData(contact);
            lastUsedId++;
        }
        return true;
    }
    else
    {
        cerr << "Nie udalo sie otworzyc pliku do zapisu.\n";
        return false;
    }
}

vector<Contact> ContactFile::loadContactsForUser(int userId)
{
    ifstream textFile(CONTACTS_DATA_FILENAME);
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

void ContactFile::updateContactInFile(const vector<Contact>& contacts, int editedContactId)
{
    ifstream inputFile(CONTACTS_DATA_FILENAME);
    ofstream tempFile("temp.txt");

    if (!inputFile.is_open() || !tempFile.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku!" << endl;
        return;
    }

    string line;
    bool contactFound = false;

    while (getline(inputFile, line)) {
        int currentId = extractContactId(line);

        if (currentId == editedContactId) {
            // Przepisanie zmodyfikowanego kontaktu z wektora
            for (const auto& contact : contacts) {
                if (contact.getId() == editedContactId) {
                    tempFile << formatContactData(contact) << endl;
                    contactFound = true;
                    break;
                }
            }
        } else {
            // Przepisanie oryginalnej linii
            tempFile << line << endl;
        }
    }

    inputFile.close();
    tempFile.close();

    remove(CONTACTS_DATA_FILENAME.c_str());
    rename("temp.txt", CONTACTS_DATA_FILENAME.c_str());

    if (!contactFound) {
        cerr << "Kontakt z podanym ID nie zosta³ znaleziony!" << endl;
    }
}

