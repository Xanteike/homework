#pragma once


#include "Day.h"
#include "Month.h"
#include "Year.h"


using Days = chrono::duration<int, ratio_multiply<ratio<24>, chrono::hours::period>>;
using Weeks = chrono::duration<int, ratio_multiply<ratio<7>, Days::period>>;

// Years - 365.2425 дня или 146097/400 дней.
// Старый римский календарь имел 365 дней.
// Юлианский календарь изменил это до 365 дней с 1 високосным годом каждые 4 года (365,25 дней).
// Григорианский календарь изменил юлианский календарь в 1582 году, пропустив високосные годы на годы,
// равномерно разделенные на 100, но не на 400. Т.е. 1700, 1800 и 1900 годы были не високосными,
// но 1600 и 2000 были. Каждые 400 лет ровно 146097 дней: 400 * 365 + 400/4 - 3
using Years = chrono::duration<int, ratio_multiply<ratio<146097, 400>, Days::period>>;

using Months = chrono::duration<int, ratio_divide<Years::period, ratio<12>>>;

enum MonthNames
{
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December,
    Max
};

class Date
{
public:
    Date() = default;
    Date(const Day& d, const Month& m, const Year& y) :
        day(d),
        month(m),
        year(y)
    {
        if(CheckForFebruaryAndNotLeapYear() || !IsValid()) {
            cout << "Date (bad date format):" << day << "." << month << "." << year << endl;
            exit(-1);
        }
    }
    Date(const Date&) = default;
    Date& operator=(const Date&) = default;

    Day GetDay() const                      { return day; }
    Month GetMonth() const                  { return month; };
    Year GetYear() const                    { return year; };

    Date& operator++();
    Date  operator++(int);
    Date& operator--();
    Date  operator--(int);

    bool IsValid() const                    { return day.IsValid(DaysInMonth[static_cast<unsigned int>(month)]) && month.IsValid() && year.IsValid(); }

    friend bool operator==(const Date& d1, const Date& d2);
    friend bool operator!=(const Date& d1, const Date& d2);
    friend bool operator<(const Date& d1, const Date& d2);
    friend bool operator>(const Date& d1, const Date& d2);
    friend bool operator<=(const Date& d1, const Date& d2);
    friend bool operator>=(const Date& d1, const Date& d2);

    friend ostream& operator<<(ostream& stream, const Date& date);

private:
    bool CheckForFebruaryAndNotLeapYear() const;

private:
    Day day;
    Month month;
    Year year;
    static constexpr int DaysInMonth[MonthNames::Max] {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

