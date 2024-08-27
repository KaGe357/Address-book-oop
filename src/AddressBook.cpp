#include "AddressBook.h"
#include <iterator>
#include <fstream>
#include <sstream>
#include "ContactManager.h"
#include "UserManager.h"



AddressBook::AddressBook()
{
    userManager.loadUsersFromFileToVector();

}
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
    contactManager.printAllContacts();
}

void AddressBook::registerNewContact()
{
    contactManager.registerNewContact(contactManager.getLoggedUserId());
}
int AddressBook::loginUser()
{
    contactManager.setLoggedUserId(userManager.loginUser()) ;
    contactManager.loadContactsForUser(contactManager.getLoggedUserId());
    return contactManager.getLoggedUserId();
}
