
#include <vector>
#include "ContactManager.h"
#include "ContactFile.h"
using namespace std;

ContactManager::ContactManager()
    : loggedUserId(0), lastUsedId(0), contactFile("Contacts.txt"), contact() {}


void ContactManager::printContactData(Contact contact)
{
    cout << endl << "Id:                 " << contact.getId() << endl;
    cout << "Imie:               " << contact.getName() << endl;
    cout << "Nazwisko:           " << contact.getLastName() << endl;
    cout << "Numer telefonu:     " << contact.getPhoneNum() << endl;
    cout << "Email:              " << contact.getEmail() << endl;
    cout << "Adres:              " << contact.getHomeAddress() << endl;
}


int ContactManager::loadContactsForUser(int loggedUserId)
{
    contacts = contactFile.loadContactsForUser(loggedUserId);
    lastUsedId = contactFile.getLastUsedId();
    return lastUsedId;
}



Contact ContactManager::giveNewContactData(int loggedUserId)
{
    Contact contact;
    contact.setId(++lastUsedId);
    contact.setUserId(loggedUserId);

    string temp;
    cout << "Podaj imie: ";
    getline(cin, temp);
    contact.setName(temp);

    cout << "Podaj nazwisko: ";
    getline(cin, temp);
    contact.setLastName(temp);

    cout << "Podaj numer telefonu: ";
    getline(cin, temp);
    contact.setPhoneNum(temp);

    cout << "Podaj email: ";
    getline(cin, temp);
    contact.setEmail(temp);

    cout << "Podaj adres: ";
    getline(cin, temp);
    contact.setHomeAddress(temp);

    return contact;
}



void ContactManager::printAllContacts()
{

    system("cls");
    if (!contacts.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Contact> :: iterator itr = contacts.begin(); itr != contacts.end(); itr++)
        {
            printContactData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }

    system("pause");
}

int ContactManager::registerNewContact(int loggedUser)
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    contact = giveNewContactData(loggedUser);
    cout <<"ContactManager::registerNewContact " << loggedUser <<endl;
    contacts.push_back(contact);
    contactFile.appendContactToFile(contact);

    return ++lastUsedId;
}

void ContactManager::setLoggedUserId(int newId)
{
    if(newId>=0) loggedUserId=newId;
}

int ContactManager::getLoggedUserId()
{
    return loggedUserId;
}


