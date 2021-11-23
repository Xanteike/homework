#pragma once

#include "Card.h"

class Hand
{
public:
    Hand() = default;
    virtual ~Hand()
    {
        Clear();
    }

    void Add(Card* c)
    {
        assert(c != nullptr);
        cards.emplace_back(c);
    }

    void Clear()
    {
        for(const auto& c: cards)
            delete c;
        cards.clear();
    }

    int GetTotal() const
    {
        const int PointsThenAceEleven = 11;

        int total = 0;
        for(const auto& c: cards) {
            total += c->GetNominal();
            if(total <= PointsThenAceEleven && c->GetFace() == CardFace::Ace)
                total += (PointsThenAceEleven-1);
        }

        return total;
    }

    void Open()
    {
        for(const auto& c: cards) {
            c->Open();
        }
    }

    void Show()
    {
        for(const auto& c: cards) {
            c->Show();
        }
        cout << endl;
    }

protected:
    vector<Card*> cards{};
};
