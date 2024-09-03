#ifndef USERFILE_H
#define USERFILE_H

#include <iostream>
#include <vector>
#include <fstream>
#include "User.h"
#include "AdditionalMethods.h"

using namespace std ;

class UserFile
{
    const string USER_DATA_FILENAME;

    bool isTheFileEmpty();
    string convertUserDataToSeparatedForFileSaves(User user);
    User getUserData(string userDataSeparatedWithVerticalLine);
    string convertIntToStr(int number);

public:
    UserFile(string userDataFilename) : USER_DATA_FILENAME(userDataFilename){};
    void appendUserToFile(User user);
    vector <User> loadUsersFromFileToVector();


};

#endif
