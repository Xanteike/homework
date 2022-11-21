#pragma once

struct PhoneNumber
{
    PhoneNumber() = default;
    PhoneNumber(int country, int city, const std::string& num, int aux = 0) :
        countryCode(country),
        cityCode(city),
        number(num),
        auxNumber(aux)
    {}
    PhoneNumber(const std::string& s, int aux = 0);

    void SetNumber(const std::string& n);
    void SetAuxNumber(const std::string& aux) { auxNumber = atoi(aux.c_str()); }

    friend ostream& operator<<(ostream& stream, const PhoneNumber& p);
    friend bool operator < (const PhoneNumber& p1, const PhoneNumber& p2);
    friend bool operator == (const PhoneNumber& p1, const PhoneNumber& p2);

    int countryCode{0};
    int cityCode{0};
    string number;
    int auxNumber{0};
};
