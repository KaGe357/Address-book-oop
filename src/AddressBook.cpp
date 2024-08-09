#include "AddressBook.h"
#include <iterator>
#include <fstream>
#include <sstream>

 AddressBook::AddressBook()
{
    userDataFileName="Users.txt";
}

void AddressBook::registerNewUser()
{
    User user = giveNewUserData();

    users.push_back(user);
    AddressBook::appendUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

bool AddressBook::isTheFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

User AddressBook::giveNewUserData()
{
    User user;

    user.setId(getNewUserId());
    string login;
    string password;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (isThereALogin(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int AddressBook::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool AddressBook::isThereALogin(string login)
{
    for(int i=0; i<users.size(); i++)
    {
        if(users[i].getLogin()==login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
}
void AddressBook::printAllUsers()
{
    for(int i=0;i<users.size();i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}
void AddressBook::appendUserToFile(User user)
{
    fstream textFile;
    string userDataLine = "";
    textFile.open(userDataFileName.c_str(), ios::app);

    if (textFile.good() == true)
    {
        userDataLine = convertUserDataToSeparatedForFileSaves(user);

        if (isTheFileEmpty(textFile) == true)
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
string AddressBook::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AddressBook::convertUserDataToSeparatedForFileSaves(User user)
{
    string userDataLine;

    userDataLine += convertIntToString(user.getId())+ '|';
    userDataLine += user.getLogin() + '|';
    userDataLine += user.getPassword() + '|';

    return userDataLine;
}
