#include "1.h"

void PrintVector(const auto& l)
{
    std::for_each(l.begin(), l.end(), [](const auto& v){ cout << v << " "; });
    cout << endl;
}

template<typename T>
void PrintUnique(T ib, T ie)
{
    set<typename T::value_type> u(ib, ie);
    PrintVector(u);
}

void Task1()
{
    vector<string> s{"First", "second", "third", "second"};
    PrintUnique(s.begin(), s.end());

    vector<int> i{1, 2, 3, 3, 3, 4, 5, 5, 6};
    PrintUnique(i.begin(), i.end());

    list<string> sl{"First", "second", "third", "second"};
    PrintUnique(sl.begin(), sl.end());

    list<int> il{1, 2, 3, 3, 3, 4, 5, 5, 6};
    PrintUnique(il.begin(), il.end());
}

void Task2()
{
    multimap<size_t, string, greater<size_t>> lines;

    while(true) {
        if(string line; !getline(cin, line)) {
            throw "Критическая ошибка ввода!!!";
        } else if(line.empty()) {
            break;
        } else
            lines.insert(make_pair(line.size(), line));
    }

    std::for_each(lines.begin(), lines.end(), [](const auto& v){ cout << v.first << ": " << v.second << "\n"; });
}
