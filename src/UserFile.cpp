#include "UserFile.h"

UserFile::UserFile()
{
    userDataFileName = "Users.txt";
}

string UserFile::convertUserDataToSeparatedForFileSaves(User user)
{
    string userDataLine;

    userDataLine += AdditionalMethods::convertIntToString(user.getId())+ '|';
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
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
