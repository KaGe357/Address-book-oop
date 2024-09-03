#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
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
    UserManager(string userDataFilename) : userFile(userDataFilename)
    {
        loggedUserId=0;
        users = userFile.loadUsersFromFileToVector();
    }
    void registerNewUser();
    void printAllUsers();
    int loginUser();
    bool isAUserLogged();
    int getLoggedUserId();
    void logoutUser();

};
#endif
