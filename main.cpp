#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
#include "AddressBook.h"


using namespace std ;

int main()
{
    AddressBook addressBook("Users.txt","Contacts.txt");

    int loggedId;
    while(!addressBook.userManager.isAUserLogged())
    {
        addressBook.printMainMenu();
            int userChoice;
        cin>>userChoice;
        cin.sync();
        switch(userChoice)
        {
        case 1:
            addressBook.registerNewUser();
            break;

        case 2:
            loggedId=addressBook.loginUser();
            break;

        case 9:
            exit(0);
            break;
        }

        while(loggedId!=0)
        {
            addressBook.printLoggedUserMenu();
                int userChoice;
            cin>>userChoice;
            cin.sync();
            switch(userChoice)
            {
            case 1:
                addressBook.registerNewContact();
                break;
            case 2:
                // addressBook.searchByName();
                break;
            case 3:
                // addressBook.searchByLastName();
                break;
            case 4:
                addressBook.printAllContacts();
                break;
            case 5:
                // addressBook.removeContact();
                break;
            case 6:
                // addressBook.modifyContactData();
                break;
            case 7:
                // addressBook.changePassword();
                break;
            case 8:
                addressBook.logoutUser();
                loggedId=0;
                break;
            }

        }

    }



}
