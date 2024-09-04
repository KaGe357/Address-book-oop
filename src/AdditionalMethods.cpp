#include "AdditionalMethods.h"
#include <algorithm>
#include <cctype>
string AdditionalMethods::getLineFromUser()
{
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}

string AdditionalMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
string AdditionalMethods::getNumber(string text, int charPosition)
{
    string number = "";
    while(isdigit(text[charPosition]) == true)
    {
        number += text[charPosition];
        charPosition ++;
    }
    return number;
}

int AdditionalMethods::getContactIdFromVerticalLineSeparatedDatas(string contactDataSeparatedWithVerticalLine)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = stoi(getNumber(contactDataSeparatedWithVerticalLine, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}



string AdditionalMethods::toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}
