#include <iostream>
#include <vector>
#include <cassert>
using namespace std;


// ----------------------                        ----------------------     
// ------------------------------ hedder ------------------------------
// ----------------------                        ----------------------


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
        if (face >= CardFace::Ace && face <= CardFace::Nine)
            return static_cast<int>(face) + 1;
        else if (face >= CardFace::Ten && face <= CardFace::King)
            return 10;

        return 0;
    }

    void Show()
    {
        cout << (isOpened ? facesChar[static_cast<size_t>(face)] : "X") << " ";
    }

private:
    bool isOpened{ false };
    CardFace face{ CardFace::Max };
    CardSuit suit{ CardSuit::Max };
    const char* facesChar[static_cast<size_t>(CardFace::Max)]{ "A","2","3","4","5","6","7","8","9","10","J","Q","K" };
};

// ----------------------                        ----------------------     
// ------------------------------ hedder ------------------------------
// ----------------------                        ----------------------


class Hand
{
public:
    Hand() = default;
    virtual ~Hand() {};

    void Add(Card* c)
    {
        assert(c != nullptr);
        cards.emplace_back(c);
    }

    void Clear()
    {
        for (const auto& c : cards)
            delete c;
        cards.clear();
    }

    int GetTotal() const
    {
        const int PointsThenAceEleven = 11;

        int total = 0;
        for (const auto& c : cards) {
            total += c->GetNominal();
            if (total <= PointsThenAceEleven && c->GetFace() == CardFace::Ace)
                total += (PointsThenAceEleven - 1);
        }
        return total;
    }

    void Open()
    {
        for (const auto& c : cards) {
            c->Open();
        }
    }

    void Show()
    {
        for (const auto& c : cards) {
            c->Show();
        }
        cout << endl;
    }

protected:
    vector<Card*> cards{};
}; class Hand
{
public:
    Hand() = default;
    virtual ~Hand() {};

    void Add(Card* c)
    {
        assert(c != nullptr);
        cards.emplace_back(c);
    }

    void Clear()
    {
        for (const auto& c : cards)
            delete c;
        cards.clear();
    }

    int GetTotal() const
    {
        const int PointsThenAceEleven = 11;

        int total = 0;
        for (const auto& c : cards) {
            total += c->GetNominal();
            if (total <= PointsThenAceEleven && c->GetFace() == CardFace::Ace)
                total += (PointsThenAceEleven - 1);
        }
        return total;
    }

    void Open()
    {
        for (const auto& c : cards) {
            c->Open();
        }
    }

    void Show()
    {
        for (const auto& c : cards) {
            c->Show();
        }
        cout << endl;
    }

protected:
    vector<Card*> cards{};
};

// ----------------------                        ----------------------     
// ------------------------------ Task 1 ------------------------------
// ----------------------                        ----------------------


template<typename T>
T GetUserInput(const string& prompt, int length = 1)
{
    while (true) {
        T val;

        cout << prompt << ": ";
        cin >> val;

        if (cin.fail() || (to_string(val).length() > length && !is_same<T, char>::value)) {
            cin.clear();
            cin.ignore(numeric_limits<T>::max(), '\n');
            cout << "Incorrect input. Try again." << endl;
        }
        else {
            cin.ignore(numeric_limits<T>::max(), '\n');
            return val;
        }
    }
}

// ----------------------                        ----------------------     
// ------------------------------ Task2 ------------------------------
// ----------------------                        ----------------------

inline ostream& endll(ostream& stream)
{
    stream << "\n\n" << flush;
    return stream;
}

// ----------------------                        ----------------------     
// ------------------------------ Task3 ------------------------------
// ----------------------                        ----------------------

class Player : public GenericPlayer
{
public:
    Player(const string& name) :
        GenericPlayer(name)
    {}

    virtual bool IsHitting() const override
    {
        char c = GetUserInput<char>(name + ", take a card?");
        return (c == 'y' || c == 'Y');
    };

    void Win() const { cout << name + " won!" << endl; }
    void Lose() const { cout << name + " lost!" << endl; }
    void Push() const { cout << "drow!" << endl; }
};


// ----------------------                        ----------------------     
// ------------------------------ Task4 ------------------------------
// ----------------------                        ----------------------

class House : public GenericPlayer
{
public:
    House(const string& name = "Dealer") :
        GenericPlayer(name)
    {}

    virtual ~House() {};

    void OpenFirstCard()
    {
        if (!(cards.empty())) {
            cards[0]->Open();
        }
        else {
            cout << "There are no cards!" << endl;
        }
    }

    virtual bool IsHitting() const
    {
        const int DecisionPoints = 16;

        return (GetTotal() <= DecisionPoints);
    };

};

// ----------------------                        ----------------------     
// ------------------------------ Task5 ------------------------------
// ----------------------                        ----------------------

class GenericPlayer : public Hand
{
public:
    GenericPlayer(const string& n) : name(n) {}
    virtual ~GenericPlayer() {};

    virtual bool IsHitting() const = 0;

    bool IsBoosted() { return (GetTotal() > PointsToWin); }
    void Bust() { cout << "The player has " << name << " overkill :(" << endl; }

    friend ostream& operator<<(ostream& stream, const GenericPlayer& p);

protected:
    string name{ "No name" };
    static const int PointsToWin{ 21 };
};

inline ostream& operator<<(ostream& stream, const GenericPlayer& p)
{
    stream << "The player has " + p.name + ": ";

    if (p.cards.empty()) {
        stream << "There are no maps.";
    }
    else {
        for (const auto& c : p.cards) {
            stream << *c << "\t";
        }

        stream << "Points: " << p.GetTotal() << endl;

    }

    return stream;
}