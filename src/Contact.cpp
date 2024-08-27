#include "Contact.h"



Contact::Contact()
{

}

void Contact::setId(int newId)
{
    if(newId>0) id = newId;
}

void Contact::setUserId(int newUserId)
{
    userId = newUserId;
}

void Contact::setName(string newName)
{
    name = newName;
}

void Contact::setLastName(string newLastName)
{
    lastName = newLastName;
}


void Contact::setPhoneNum(string newPhoneNum)
{
    phoneNum = newPhoneNum;
}

void Contact::setHomeAddress(string newHomeAddress)
{
    homeAddress = newHomeAddress;
}

void Contact::setEmail(string newEmail)
{
    email = newEmail;
}


int Contact::getId()  const
{
    return id;
}

int Contact::getUserId() const
{
    return userId;
}

string Contact::getName() const
{
    return name;
}

string Contact::getLastName() const
{
    return lastName;
}



string Contact::getPhoneNum() const
{
    return phoneNum;
}

string Contact::getHomeAddress() const
{
    return homeAddress;
}

string Contact::getEmail() const
{
    return email;
}
