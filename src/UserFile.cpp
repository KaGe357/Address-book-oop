#include "UserFile.h"

UserFile::UserFile():userDataFileName("Users.txt") {}


vector <User>  UserFile::loadUsersFromFileToVector()
{
    fstream textFile;
    User user;
    vector <User> users;
    string userDataSeparatedWithVerticalLine = "";


    textFile.open(userDataFileName.c_str(), ios::in);

    if (textFile.good() == true)
    {
        while (getline(textFile, userDataSeparatedWithVerticalLine))
        {
            user = getUserData(userDataSeparatedWithVerticalLine);
            users.push_back(user);
        }
        textFile.close();
    }
    return users;
}

User UserFile::getUserData(string userDataSeparatedWithVerticalLine)
{
    User user;
    string singleUserData = "";
    int singleUserDataNumber = 1;

    for (int charPosition = 0; charPosition < userDataSeparatedWithVerticalLine.length(); charPosition++)
    {
        if (userDataSeparatedWithVerticalLine[charPosition] != '|')
        {
            singleUserData += userDataSeparatedWithVerticalLine[charPosition];
        }
        else
        {
            switch(singleUserDataNumber)
            {
            case 1:
                user.setId(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setLogin(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            singleUserDataNumber++;
        }
    }
    return user;
}

string UserFile::convertUserDataToSeparatedForFileSaves(User user)
{
    string userDataLine;
    AdditionalMethods am;

    userDataLine += am.convertIntToString(user.getId())+ '|';
    userDataLine += user.getLogin() + '|';
    userDataLine += user.getPassword() + '|';

    return userDataLine;
}

void UserFile::appendUserToFile(User user)
{
    fstream textFile;
    string userDataLine = "";
    textFile.open(userDataFileName.c_str(), ios::app);

    if (textFile.good() == true)
    {
        userDataLine = convertUserDataToSeparatedForFileSaves(user);

        if (isTheFileEmpty() == true)
        {
            textFile << userDataLine;
        }
        else
        {
            textFile << endl << userDataLine ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << userDataFileName << " i zapisac w nim danych." << endl;
    textFile.close();
}


bool UserFile::isTheFileEmpty()
{
    fstream textFile;
    textFile.open(userDataFileName.c_str(), ios::in);
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
