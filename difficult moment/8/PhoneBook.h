#pragma once

#include "Person.h"
#include "PhoneNumber.h"

class PhoneBook
{
public:
    PhoneBook() = default;
    PhoneBook(ifstream& ifs);

    friend ostream& operator<<(ostream& stream, const PhoneBook& p);

    void SortByName();
    void SortByPhone();
    tuple<string, PhoneNumber> GetPhoneNumber(const string& s);
    void ChangePhoneNumber(Person p, PhoneNumber pn);

private:
    vector<pair<Person, PhoneNumber>> peoples{};
};