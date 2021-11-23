#pragma once

#include "Hand.h"

class GenericPlayer : public Hand
{
public:
    GenericPlayer(const string& n) : name(n) {}
    virtual ~GenericPlayer(){};

    virtual bool IsHitting() const = 0;

    bool IsBusted() { return (GetTotal() > PointsToWin); }
    void Bust() { cout << "The player has " << name << " enumeration :(" << endl; }

    friend ostream& operator<<(ostream& stream, const GenericPlayer& p);

protected:
    string name{"No name"};
    static const int PointsToWin{21};
};

inline ostream& operator<<(ostream& stream, const GenericPlayer& p)
{
    stream << "The player has " + p.name + ": ";

    if(p.cards.empty()) {
        stream << "There are no maps.";
    } else {
        for(const auto& c: p.cards) {
            stream << *c << "\t";
        }

        stream << "Points: " << p.GetTotal() << endl;

    }

    return stream;
}
