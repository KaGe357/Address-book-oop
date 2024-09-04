#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <sstream>

using namespace std ;

class AdditionalMethods
{
public:
    string convertIntToString(int number);
    string getNumber(string tekst, int pozycjaZnaku);
    int getContactIdFromVerticalLineSeparatedDatas(string daneJednegoAdresataOddzielonePionowymiKreskami);
    string getLineFromUser();
    string toLowerCase(const string& str);


};

#endif
