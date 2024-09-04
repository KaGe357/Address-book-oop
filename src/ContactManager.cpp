
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

void ContactManager::modifyContact(int idToModify)
{
    int i = 0;
    string temp = "";
    while (contacts[i].getId() != idToModify) i++;
        cout << "Id:                     " << contacts[i].getId() << endl;
        cout << "Imie:                   " << contacts[i].getName() << endl;
        cout << "Nazwisko:               " << contacts[i].getLastName() << endl;
        cout << "Numer telefonu:         " << contacts[i].getPhoneNum() << endl;
        cout << "Email:                  " << contacts[i].getEmail() << endl;
        cout << "Adres:                  " << contacts[i].getHomeAddress() << endl << endl;

    char option;
    cout << "Wybierz dane do edycji." << endl;
    cout << "1. Imie" << endl;
    cout << "2. Nazwisko." << endl;
    cout << "3. Numer telefonu." << endl;
    cout << "4. Adres e-mail." << endl;
    cout << "5. Adres domowy." << endl;
    cout << "9. Powrot do menu glownego"<<endl;
    cin >> option;

    switch (option)
    {
    case '1':
        cout << "Podaj nowe imie: ";
        cin >> temp;
        contacts[i].setName(temp);
        break;
    case '2':
        cout << "Podaj nowe nazwisko: ";
        cin >> temp;
        contacts[i].setLastName(temp);
        break;
    case '3':
        cout << "Podaj nowy numer telefonu: ";
        cin >> temp;
        contacts[i].setPhoneNum(temp);
        break;
    case '4':
        cout << "Podaj nowy email: ";
        cin >> temp;
        contacts[i].setEmail(temp);
        break;
    case '5':
        cout << "Podaj nowy adres: ";
        cin >> temp;
        contacts[i].setHomeAddress(temp);
        break;
    case '9':
        break;
    }

    cout << "Kontakt zmieniony" << endl;
    system("cls");
        cout << "Id:                     " << contacts[i].getId() << endl;
        cout << "Imie:                   " << contacts[i].getName() << endl;
        cout << "Nazwisko:               " << contacts[i].getLastName() << endl;
        cout << "Numer telefonu:         " << contacts[i].getPhoneNum() << endl;
        cout << "Email:                  " << contacts[i].getEmail() << endl;
        cout << "Adres:                  " << contacts[i].getHomeAddress() << endl << endl;

        system("pause");

    contactFile.updateContactInFile(contacts,idToModify);
}

void ContactManager::removeContact(int idToRemove)
{
    int i = 0;
    bool contactFound = false;

    // Szukanie kontaktu o podanym ID
    while (i < contacts.size())
    {
        if (contacts[i].getId() == idToRemove)
        {
            contactFound = true;
            break;
        }
        i++;
    }

    if (!contactFound)
    {
        cout << "Kontakt o podanym ID nie zosta³ znaleziony." << endl;
        return;
    }

    // Wypisanie danych kontaktu przed usuniêciem
    cout << "Znaleziono kontakt: " << endl;
    cout << "ID: " << contacts[i].getId() << endl;
    cout << "Imiê: " << contacts[i].getName() << endl;
    cout << "Nazwisko: " << contacts[i].getLastName() << endl;
    cout << "Numer telefonu: " << contacts[i].getPhoneNum() << endl;
    cout << "Adres e-mail: " << contacts[i].getEmail() << endl;
    cout << "Adres: " << contacts[i].getHomeAddress() << endl;

    // Potwierdzenie usuniêcia
    char confirmation;
    cout << "Czy na pewno chcesz usun¹æ ten kontakt? (t/n): ";
    cin >> confirmation;

    if (confirmation == 't' || confirmation == 'T')
    {
        // Usuniêcie kontaktu z wektora
        contacts.erase(contacts.begin() + i);

        // Zaktualizowanie pliku po usuniêciu kontaktu
        contactFile.updateContactInFile(contacts, idToRemove);

        cout << "Kontakt zosta³ usuniêty." << endl;
    }
    else
    {
        cout << "Anulowano usuniêcie kontaktu." << endl;
    }
}
void ContactManager::searchContactsByName()
{
    cout << "Podaj imiê do wyszukania (lub wpisz 'exit' aby anulowaæ): ";
    string name;
    cin >> name;

    if (name == "exit")
    {
        cout << "Anulowano wyszukiwanie." << endl;
        return;
    }

    name = am.toLowerCase(name);

    bool found = false;
    cout << "Wyniki wyszukiwania dla imienia: " << name << endl;

    for (const Contact& contact : contacts)
    {
        if (am.toLowerCase(contact.getName()) == name)
        {
            cout << "ID: " << contact.getId() << endl;
            cout << "Imiê: " << contact.getName() << endl;
            cout << "Nazwisko: " << contact.getLastName() << endl;
            cout << "Numer telefonu: " << contact.getPhoneNum() << endl;
            cout << "Adres e-mail: " << contact.getEmail() << endl;
            cout << "Adres: " << contact.getHomeAddress() << endl;
            cout << "-----------------------------" << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Brak kontaktów o podanym imieniu." << endl;
    }
}
void ContactManager::searchContactsByLastName()
{
    cout << "Podaj nazwisko do wyszukania (lub wpisz 'exit' aby anulowac): ";
    string lastName;
    cin >> lastName;

    if (lastName == "exit")
    {
        cout << "Anulowano wyszukiwanie." << endl;
        return;
    }

    lastName = am.toLowerCase(lastName);

    bool found = false;
    cout << "Wyniki wyszukiwania dla nazwiska: " << lastName << endl;

    for (const Contact& contact : contacts)
    {
        if (am.toLowerCase(contact.getLastName()) == lastName)
        {
            cout << "ID: " << contact.getId() << endl;
            cout << "Imiê: " << contact.getName() << endl;
            cout << "Nazwisko: " << contact.getLastName() << endl;
            cout << "Numer telefonu: " << contact.getPhoneNum() << endl;
            cout << "Adres e-mail: " << contact.getEmail() << endl;
            cout << "Adres: " << contact.getHomeAddress() << endl;
            cout << "-----------------------------" << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "Brak kontaktów o podanym nazwisku." << endl;
    }
}

