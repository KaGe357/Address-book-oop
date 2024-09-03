
#include <vector>
#include "ContactManager.h"
#include "ContactFile.h"
using namespace std;

//ContactManager::ContactManager(contactFile.CONTACTS_DATA_FILENAME, getLoggedUserId()){};

void ContactManager::printContactData(Contact contact)
{
    cout << endl << "Id:                 " << contact.getId() << endl;
    cout << "Imie:               " << contact.getName() << endl;
    cout << "Nazwisko:           " << contact.getLastName() << endl;
    cout << "Numer telefonu:     " << contact.getPhoneNum() << endl;
    cout << "Email:              " << contact.getEmail() << endl;
    cout << "Adres:              " << contact.getHomeAddress() << endl;
}

/*
int ContactManager::loadContactsForUser(int loggedUserId)
{
    contacts = contactFile.loadContactsForUser(loggedUserId);
    lastUsedId = contactFile.getLastUsedId();
    return lastUsedId;
}
*/


Contact ContactManager::giveNewContactData()
{
    Contact contact;
    contact.setId(contactFile.getLastUsedId()+1);
    contact.setUserId(LOGGED_USER_ID);

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

void ContactManager::registerNewContact()
{
    Contact contact;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    contact = giveNewContactData();
    contacts.push_back(contact);

    if(contactFile.appendContactToFile(contact))
        cout << "Nowy adresat zostal dodany"<<endl;
    else
        cerr << "Blad. Nie udalo sie dodac nowego adresata do pliku.";
    system("pause");

}
/*
void ContactManager::setLoggedUserId(int newId)
{
    if(newId>=0) loggedUserId=newId;
}
*/
int ContactManager::getLoggedUserId()
{
    return loggedUserId;
}


