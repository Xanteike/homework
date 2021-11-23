#pragma once

enum class CardFace : int
{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Max
};

enum class CardSuit : int
{
    Heart,
    Spade,
    Club,
    Diamond,
    Max
};

class Card
{
public:
    Card() = default;
    Card(CardFace f, CardSuit s, bool opened = false) :
        face(f),
        suit(s),
        isOpened(opened)
    {
    }

    int Open() { isOpened = true; return GetNominal(); }
    bool IsOpened() { return isOpened; }
    CardFace GetFace() { return face; }
    void Flip() { isOpened = !isOpened; }

    int GetNominal()
    {
        if(face >= CardFace::Ace && face <= CardFace::Nine)
            return static_cast<int>(face) + 1;
        else if(face >= CardFace::Ten && face <= CardFace::King)
            return static_cast<int>(CardFace::Ten);

        return 0;
    }

    void Show()
    {
        cout << *this;
    }

    friend ostream& operator<<(ostream& os, const Card& c);

private:
    bool isOpened{false};
    CardFace face{CardFace::Max};
    CardSuit suit{CardSuit::Max};
};

inline ostream& operator<<(ostream& os, const Card& c)
{
    const array<string, static_cast<size_t>(CardFace::Max)> facesChar{"A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    const array<string, static_cast<size_t>(CardSuit::Max)> suitsChar{"H","S","C","D"};

    if(c.isOpened) {
        os << facesChar[static_cast<size_t>(c.face)] << suitsChar[static_cast<size_t>(c.suit)];
    } else {
        os << "XX";
    }

    return os;
}
