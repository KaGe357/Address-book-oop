#include "UserManager.h"


void UserManager::registerNewUser()
{
    User user = giveNewUserData();

    users.push_back(user);
    userFile.appendUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
int UserManager::loginUser()
{
    User user;
    int id;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    getline(cin,login);

    for(int i=0; i<users.size(); i++)
    {
        if(users[i].getLogin() == login)
        {
            for (int tries = 3; tries > 0; tries--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << tries << ": ";
                getline(cin,password);

                if (users[i].getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    id = users[i].getId();
                    cout <<"UserManager::loginUser()" << id <<endl;
                    return id;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

User UserManager::giveNewUserData()
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

int UserManager::getNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isThereALogin(string login)
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
void UserManager::printAllUsers()
{
    for(int i=0; i<users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UserManager::loadUsersFromFileToVector()
{
    users = userFile.loadUsersFromFileToVector();
}
