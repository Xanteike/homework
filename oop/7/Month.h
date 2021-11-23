#pragma once

class Month
{
public:
    Month() = default;
    Month(unsigned int m) : month(m) {}
    Month(const Month&) = default;
    Month& operator=(const Month&) = default;

    Month& operator++()                     { *this += Months{1}; return *this; }
    Month  operator++(int)                  { auto curMonth(*this); ++(*this); return curMonth; }
    Month& operator--()                     { *this -= Months{1}; return *this; }
    Month  operator--(int)                  { auto curMonth(*this); --(*this); return curMonth; }

    Month& operator+=(const Months& m)      { *this = *this + m; return *this; }
    Month& operator-=(const Months& m)      { *this = *this - m; return *this; }

    operator unsigned int() const           { return month; }
    bool IsValid() const                    { return month >= FIRST_MONTH && month <= LAST_MONTH; }

    friend bool operator==(const Month& m1, const Month& m2);
    friend bool operator!=(const Month& m1, const Month& m2);
    friend bool operator< (const Month& m1, const Month& m2);
    friend bool operator> (const Month& m1, const Month& m2);
    friend bool operator<=(const Month& m1, const Month& m2);
    friend bool operator>=(const Month& m1, const Month& m2);
    friend Month operator+(const Month& m1, const Months& m);
    friend Month operator+(const Months& m, const Month& m2);
    friend Month operator-(const Month& m1, const Months& m);
    friend Months operator-(const Month& m1, const Month& m2);
    friend ostream& operator<<(ostream& os, const Month& m);

    static unsigned int Minimal()           { return FIRST_MONTH; }
    static unsigned int Maximal()           { return LAST_MONTH; }

private:
    unsigned int month{1};
    static const int FIRST_MONTH{1};
    static const int LAST_MONTH{12};
};

inline bool operator==(const Month& m1, const Month& m2)
{
    return static_cast<unsigned int>(m1) == static_cast<unsigned int>(m2);
}

inline bool operator!=(const Month& m1, const Month& m2)
{
    return !(m1 == m2);
}

inline bool operator<(const Month& m1, const Month& m2)
{
    return static_cast<unsigned int>(m1) < static_cast<unsigned int>(m2);
}

inline bool operator>(const Month& m1, const Month& m2)
{
    return m2 < m1;
}

inline bool operator<=(const Month& m1, const Month& m2)
{
    return !(m2 < m1);
}

inline bool operator>=(const Month& m1, const Month& m2)
{
    return !(m1 < m2);
}

inline Month operator+(const Month& m1, const Months& m)
{
    auto const mu = static_cast<long long>(static_cast<unsigned int>(m1)) + m.count() - 1;
    auto const yr = (mu >= 0 ? mu : mu-11) / 12;
    return Month{static_cast<unsigned int>(mu - yr * 12 + 1)};
}

inline Month operator+(const Months& m, const Month& m2)
{
    return m2 + m;
}

inline Month operator-(const Month& m1, const Months& m)
{
    return m1 + -m;
}

inline Months operator-(const Month& m1, const Month& m2)
{
    auto const m = static_cast<unsigned int>(m1) - static_cast<unsigned int>(m2);
    return Months(m <= 11 ? m : m + 12);
}

inline ostream& operator<<(ostream& os, const Month& m)
{
    os.fill('0');
    os.flags(ios::dec | ios::right);
    os.width(2);
    os << static_cast<unsigned int>(m);

    if (!m.IsValid())
        os << "invalid month format.";

    return os;
}
