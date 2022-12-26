#include "1.h"
#include "PhoneNumber.h"

PhoneNumber::PhoneNumber(const string& s, int auxn)
{
    SetNumber(s);
    auxNumber = auxn;
}

void PhoneNumber::SetNumber(const string& n)
{
    regex re("^\\+(\\d+)\\((\\d+)\\)(\\d+)$");
    smatch match;
    if(regex_match(n, match, re)) {
        countryCode = atoi(match[1].str().c_str());
        cityCode = atoi(match[2].str().c_str());
        number = match[3].str();
    } else
        throw "Не известный формат номера телефона";
}

ostream& operator<<(ostream& stream, const PhoneNumber& p)
{
    stream << "+" << p.countryCode;
    stream << "(" << p.cityCode << ")";
    stream << p.number;

    if(p.auxNumber)
        stream << " " << p.auxNumber;

    return stream;
}

bool operator < (const PhoneNumber& p1, const PhoneNumber& p2)
{
    return tie(p1.countryCode, p1.cityCode, p1.number, p1.auxNumber)
           <
           tie(p2.countryCode, p2.cityCode, p2.number, p2.auxNumber);
}

bool operator == (const PhoneNumber& p1, const PhoneNumber& p2)
{
    return tie(p1.countryCode, p1.cityCode, p1.number, p1.auxNumber)
           ==
           tie(p2.countryCode, p2.cityCode, p2.number, p2.auxNumber);
}
