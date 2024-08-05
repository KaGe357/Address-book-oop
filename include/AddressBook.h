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

public:
    void registerNewUser();
};
