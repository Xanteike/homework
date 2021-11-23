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
    virtual ~Hand(){};

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
        std::cout << std::endl;
    }

protected:
    std::vector<Card*> cards{};
};

// ----------------------                        ----------------------     
// ------------------------------ Task 1 ------------------------------
// ----------------------                        ----------------------

template<typename T>
class Pair1
{
public:
    Pair1(const T& p1, const T& p2) :
        param1(p1),
        param2(p2)
    {}

    void SetParam1(const T& p) { param1 = p; }
    void SetParam2(const T& p) { param2 = p; }

    T First() const { return param1; }
    T Second() const { return param2; }

private:
    T param1{};
    T param2{};
};

// ----------------------                        ----------------------     
// ------------------------------ Task 2 ------------------------------
// ----------------------                        ----------------------

template<typename T1, typename T2>
class Pair
{
public:
    Pair(const T1& p1, const T2& p2) :
        param1(p1),
        param2(p2)
    {}

    void SetParam1(const T1& p) { param1 = p; }
    void SetParam2(const T2& p) { param2 = p; }

    T1 First() const { return param1; }
    T2 Second() const { return param2; }

private:
    T1 param1{};
    T2 param2{};
};

// ----------------------                        ----------------------     
// ------------------------------ Task 3 ------------------------------
// ----------------------                        ----------------------

template<typename T>
class StringValuePair : public Pair<string, T>
{
public:
    StringValuePair(const string& s, T v) :
        Pair<string, T>(s, v)
    {}
};

// ----------------------                        ----------------------     
// ------------------------------ Task 4 ------------------------------
// ----------------------                        ----------------------

class GenericPlayer : public Hand
{
public:
    GenericPlayer() : Hand() {}

    virtual bool IsHitting() = 0;

    bool IsBoosted() { return false; }
    void Bust() { cout << "The player has " << name << " overkill :(" << endl; }

private:
    string name{ "No name" };
};