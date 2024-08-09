#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class AddressBook
{
      int idOfLoggedUser;
    int idOfLastContact;
    int idOfRemovedContact;

    string userDataFileName;


    vector <User> users;

    User giveNewUserData();
    int getNewUserId();
    bool isThereALogin(string login);
    void appendUserToFile(User user);
    bool isTheFileEmpty(fstream& textFile);
    string convertUserDataToSeparatedForFileSaves(User user);
    string convertIntToString(int number);

public:
    AddressBook();
    void registerNewUser();
    void printAllUsers();


};
