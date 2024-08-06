#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class AddressBook
{
      int idOfLoggedUser;
    int idOfLastContact;
    int idOfRemovedContact;

    vector <User> users;

    User giveNewUserData();
    int getNewUserId();
    bool isThereALogin(string login);

public:
    void registerNewUser();
    void printAllUsers();

};
