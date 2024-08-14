#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>

#include "User.h"
#include "AdditionalMethods.h"

using namespace std;

class UserFile
{
    string userDataFileName;
    fstream textFile;

    bool isTheFileEmpty();
    string convertUserDataToSeparatedForFileSaves(User user);
    User getUserData(string userDataSeparatedWithVerticalLine);

public:
    UserFile();
    void appendUserToFile(User user);
    vector <User> loadUsersFromFileToVector();


};

#endif
