#include "AddressBook.h"
#include <iterator>
#include <string>
#include <fstream>
#include <sstream>
#include "ContactManager.h"
#include "UserManager.h"




void AddressBook::registerNewUser()
{
    userManager.registerNewUser();
}
void AddressBook::printAllUsers()
{
    userManager.printAllUsers();
}

void AddressBook::printAllContacts()
{
    contactManager->printAllContacts();
}

void AddressBook::registerNewContact()
{
    if(loggedId!=0)
    {
        contactManager->registerNewContact();
    }
}
int AddressBook::loginUser()
{
     loggedId=userManager.loginUser();
    if(loggedId!=0)
    {
        contactManager = new ContactManager(CONTACT_DATA_FILENAME, loggedId);
        return loggedId;
    }
    else
    {
        cout << "Aby dodac adresata, nalezy sie najpierw zalogowac." << endl;
        system("pause");
    }
}

void AddressBook::logoutUser()
{
    userManager.logoutUser();
    delete contactManager;
    contactManager= NULL;

}

void AddressBook::printMainMenu()
{
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

}
void AddressBook::printLoggedUserMenu()
{
        system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";


    }
