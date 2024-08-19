#include "AddressBook.h"
#include <iterator>
#include <fstream>
#include <sstream>
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

