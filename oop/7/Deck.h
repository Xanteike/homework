#pragma once

class Deck : public Hand
{
public:
    Deck()
    {
        cards.reserve(DeckSize);
        Populate();
    }

    void Populate()
    {
        Clear();

        for(int s = 0; s < static_cast<int>(CardSuit::Max); ++s) {
            for(int f = 0; f < static_cast<int>(CardFace::Max); ++f) {
                Add(new Card(static_cast<CardFace>(f), static_cast<CardSuit>(s)));
            }
        }
    }

    void Shuffle()
    {
        default_random_engine rnd(chrono::system_clock::now().time_since_epoch().count());
        shuffle(cards.begin(), cards.end(), rnd);
    }

    void Deal(Hand& hand)
    {
        if(!cards.empty()) {
            hand.Add(cards.back());
            cards.pop_back();
        } else {
            cout << "The deck is empty. There's nothing to give away.";
        }
    }

    void AdditionalCards(GenericPlayer& genericPlayer)
    {
        cout << endl;

        while (!(genericPlayer.IsBusted()) && genericPlayer.IsHitting())
        {
            Deal(genericPlayer);
            cout << genericPlayer << endl;

            if (genericPlayer.IsBusted()) {
                genericPlayer.Bust();
            }
        }
    }

private:
    const int DeckSize{52};
};
