#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
#include "AddressBook.h"


using namespace std ;

int main()
{

    AddressBook addressBook;

//   addressBook.registerNewUser();
    //  addressBook.printAllUsers();


       addressBook.loginUser();
   addressBook.registerNewContact();
    addressBook.printAllContacts();

}
