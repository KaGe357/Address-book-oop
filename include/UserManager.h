#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "UserFile.h"

using namespace std;

class UserManager
{

    int loggedUserId;
    vector<User>users;

    User giveNewUserData();
    int getNewUserId();
    bool isThereALogin(string login);
    UserFile userFile;


public:
    void registerNewUser();
    void printAllUsers();
   void loadUsersFromFileToVector();

};
#endif
