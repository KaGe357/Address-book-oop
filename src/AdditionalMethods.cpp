#include "AdditionalMethods.h"


string AdditionalMethods::convertIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
