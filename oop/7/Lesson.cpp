#include "Lesson.h"

void Lesson::Task1()
{
    cout << "--------------------------" << endl;
    cout << "Checking for a leap year" << endl;
    cout << "--------------------------" << endl;

    Date dleap1(1,3,2020);
    cout << "Start date (leap year): " << dleap1 << endl;
    cout << "Date minus 1 day (leap year): " << --dleap1 << endl;
    cout << "Add 1 day (leap year):" << ++dleap1 << endll;

    Date dleap2(1,3,2021);
    cout << "Start date (non-leap year):" << dleap2 << endl;
    cout << "Date minus 1 day (non-leap year):" << --dleap2 << endl;
    cout << "Adding 1 day (non-leap year): " << ++dleap2 << endll;


    time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm* now = localtime(&tt);

    SmartPtr<Date> today(new Date(now->tm_mday,now->tm_mon,now->tm_year + 1900));
    SmartPtr<Date> date;
    cout << "Current date (today): " << *today << endl;
    cout << "today = " << (today.Get() != nullptr ? today.Get() : nullptr) << endl;
    cout << "date = " << (date.Get() != nullptr ? date.Get() : nullptr) << endl;

    date = today;
    cout << "Current date (date): " << *date << endl;
    cout << "today = " << (today.Get() != nullptr ? today.Get() : nullptr) << endl;
    cout << "date = " << (date.Get() != nullptr ? date.Get() : nullptr) << endl;
}

const SmartPtr<Date>& CompareDatesNoEqual(const SmartPtr<Date>& d1, const SmartPtr<Date>& d2)
{
    return *d1 > *d2 ? d1 : d2;
}

void ExchangeDates(SmartPtr<Date>& d1, SmartPtr<Date>& d2)
{
    SmartPtr<Date> temp(d1);
    d1 = d2;
    d2 = temp;
}

void Lesson::Task2()
{


    SmartPtr<Date> date1(new Date(10,4,2021));
    SmartPtr<Date> date2(new Date(5, 8, 2020));

    cout << "Date 1: " << *date1 << endl;
    cout << "Date 2: " << *date2 << endl;

    cout << "Compare, return the largest: " << *CompareDatesNoEqual(date1, date2) << endl;
    cout << "We exchange dates." << endl;
    ExchangeDates(date1, date2);
    cout << "Date 1: " << *date1 << endl;
    cout << "Date 2: " << *date2 << endl;

}

void Lesson::BlackjackTest()
{
    cout << "=========================" << endl;
    cout << "Blackjack test" << endl;
    cout << "=========================" << endl;

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7) {
        numPlayers = GetUserInput<int>("СHow many players will there be?(1 - 7)");
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Enter the player's name" << i+1 << ": ";
        cin >> name;
        names.emplace_back(name);
    }
    cout << endl;

    Game game(names);
    char again = 'y';
    while (again != 'n' && again != 'N') {
        game.Play();
        again = GetUserInput<char>("Shall we play some more? (Y/N)");
    }
}
