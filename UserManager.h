#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <windows.h>

using namespace std;

class UserManager
{

    int idZalogowanegoUzytkownika;
    vector<User>users;

    User giveNewUserData();
    int getNewUserId();
    bool isThereALogin(string login);
    string convertUserDataToSeparatedForFileSaves(User user);


public:

    void registerNewUser();
    void printAllUsers();


};
