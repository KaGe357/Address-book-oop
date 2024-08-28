#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>

using namespace std;

class Contact
{
    int id;
    int userId;
    string name;
    string lastName;
    string phoneNum;
    string email;
    string homeAddress;


public:
    Contact(int id, int userId, const std::string& name, const std::string& lastName,
            const std::string& phoneNumber, const std::string& email, const std::string& homeAddress)
        : id(id), userId(userId), name(name), lastName(lastName),
          phoneNum(phoneNumber), email(email), homeAddress(homeAddress) {}  // Poprawka
    Contact();

    void setId(int newId);
    void setUserId(int newUserId);
    void setName(string newName);
    void setLastName(string newLastName);
    void setPassword(string newPassword);
    void setPhoneNum(string newPhoneNum);
    void setHomeAddress(string newHomeAddress);
    void setEmail(string newEmail);

    int getId() const;
    int getUserId() const ;
    string getName() const ;
    string getLastName() const ;
    string getPhoneNum() const ;
    string getPassword() const;
    string getHomeAddress() const ;
    string getEmail() const ;


};




#endif
