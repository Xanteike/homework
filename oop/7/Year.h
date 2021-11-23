#pragma once

class Year
{
public:
    Year() = default;
    Year(int y) : year(y) {}
    Year(const Year&) = default;
    Year& operator=(const Year&) = default;

    Year& operator++()                  { ++year; return *this; }
    Year  operator++(int)               { auto curYear(*this); ++(*this); return curYear; }
    Year& operator--()                  { --year; return *this; }
    Year  operator--(int)               { auto curYear(*this); --(*this); return curYear; }

    Year& operator+=(const Years& y)    { *this = *this + y; return *this; }
    Year& operator-=(const Years& y)    { *this = *this - y; return *this; }

    Year operator-() const              { return Year{-year}; }
    Year operator+() const              { return *this; }

    bool IsLeap() const                 { return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0); }

    operator int() const                { return year; }
    bool IsValid() const                { return year != std::numeric_limits<int>::min(); }

    static Year Minimal()               { return Year{std::numeric_limits<int>::min()}; }
    static Year Maximal()               { return Year{std::numeric_limits<int>::max()}; }

    friend bool operator==(const Year& y1, const Year& y2);
    friend bool operator!=(const Year& y1, const Year& y2);
    friend bool operator<(const Year& y1, const Year& y2);
    friend bool operator>(const Year& y1, const Year& y2);
    friend bool operator<=(const Year& y1, const Year& y2);
    friend bool operator>=(const Year& y1, const Year& y2);
    friend Year operator+(const Year& y1, const Years& y);
    friend Year operator+(const Years& y, const Year& y2);
    friend Year operator-(const Year& y1, const Years& y);
    friend Years operator-(const Year& y1, const Year& y2);
    friend std::ostream& operator<<(std::ostream& os, const Year& y);

private:
    int year{2021};
};

inline bool operator==(const Year& y1, const Year& y2)
{
    return static_cast<int>(y1) == static_cast<int>(y2);
}

inline bool operator!=(const Year& y1, const Year& y2)
{
    return !(y1 == y2);
}

inline bool operator<(const Year& y1, const Year& y2)
{
    return static_cast<int>(y1) < static_cast<int>(y2);
}

inline bool operator>(const Year& y1, const Year& y2)
{
    return y2 < y1;
}

inline bool operator<=(const Year& y1, const Year& y2)
{
    return !(y2 < y1);
}

inline bool operator>=(const Year& y1, const Year& y2)
{
    return !(y1 < y2);
}

inline Year operator+(const Year& y1, const Years& y)
{
    return Year{static_cast<int>(y1) + y.count()};
}

inline Year operator+(const Years& y, const Year& y2)
{
    return y2 + y;
}

inline Year operator-(const Year& y1, const Years& y)
{
    return Year{static_cast<int>(y1) - y.count()};
}

inline Years operator-(const Year& y1, const Year& y2)
{
    return Years{static_cast<int>(y1) - static_cast<int>(y2)};
}

inline std::ostream& operator<<(std::ostream& os, const Year& y)
{
    os.fill('0');
    os.flags(std::ios::dec | std::ios::internal);
    os.width(4 + (y < Year{0}));
    os.imbue(std::locale::classic());
    os << static_cast<int>(y);

    if (!y.IsValid())
        os << " invalid year format.";

    return os;
}

