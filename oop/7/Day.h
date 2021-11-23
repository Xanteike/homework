#pragma once

class Day
{
public:
    Day() = default;
    Day(unsigned int d) : day(d) {};
    Day(const Day&) = default;
    Day& operator=(const Day&) = default;

    Day& operator++()                       { ++day; return *this; }
    Day  operator++(int)                    { auto curDay(*this); ++(*this); return curDay; }
    Day& operator--()                       { --day; return *this; }
    Day  operator--(int)                    { auto curDay(*this); --(*this); return curDay; }

    Day& operator+=(const Days& d)          { *this = *this + d; return *this; }
    Day& operator-=(const Days& d)          { *this = *this - d; return *this; }

    operator unsigned int() const           { return day; }
    bool IsValid(int validay = LAST_DAY) const { return day >= FIRST_DAY && day <= validay; }

    static unsigned int Minimal()           { return FIRST_DAY; }
    static unsigned int Maximal()           { return LAST_DAY; }

    friend bool operator==(const Day& d1, const Day& d2);
    friend bool operator!=(const Day& d1, const Day& d2);
    friend bool operator<(const Day& d1, const Day& d2);
    friend bool operator>(const Day& d1, const Day& d2);
    friend bool operator<=(const Day& d1, const Day& d2);
    friend bool operator>=(const Day& d1, const Day& d2);
    friend Day operator+(const Day& d1, const Days& d);
    friend Day operator+(const Days& x, const Day& d2);
    friend Day operator-(const Day& d1, const Days& d);
    friend Days operator-(const Day& d1, const Day& d2);
    friend ostream& operator<<(ostream& os, const Day& d);

private:
    unsigned int day{1};
    static const int FIRST_DAY{1};
    static const int LAST_DAY{31};
};

inline bool operator==(const Day& d1, const Day& d2)
{
    return static_cast<unsigned int>(d1) == static_cast<unsigned int>(d2);
}

inline bool operator!=(const Day& d1, const Day& d2)
{
    return !(d1 == d2);
}

inline bool operator<(const Day& d1, const Day& d2)
{
    return static_cast<unsigned int>(d1) < static_cast<unsigned int>(d2);
}

inline bool operator>(const Day& d1, const Day& d2)
{
    return d2 < d1;
}

inline bool operator<=(const Day& d1, const Day& d2)
{
    return !(d2 < d1);
}

inline bool operator>=(const Day& d1, const Day& d2)
{
    return !(d1 < d2);
}

inline Day operator+(const Day& d1, const Days& d)
{
    return Day{static_cast<unsigned int>(d1) + static_cast<unsigned int>(d.count())};
}

inline Day operator+(const Days& d, const Day& d2)
{
    return d2 + d;
}

inline Day operator-(const Day& d1, const Days& d)
{
    return d1 + -d;
}

inline Days operator-(const Day& d1, const Day& d2)
{
    return Days{static_cast<Days::rep>(static_cast<unsigned int>(d1) - static_cast<unsigned int>(d2))};
}

inline ostream& operator<<(ostream& os, const Day& d)
{
    os.fill('0');
    os.flags(ios::dec | ios::right);
    os.width(2);
    os << static_cast<unsigned int>(d);

    if (!d.IsValid())
        os << "incorrect format of the day.";

    return os;
}
