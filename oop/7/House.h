#pragma once

class House : public GenericPlayer
{
public:
    House(const string& name = "Dealer") :
        GenericPlayer(name)
    {}

    virtual ~House() {};

    void OpenFirstCard()
    {
        if(!(cards.empty())) {
            cards[0]->Open();
        } else {
            cout << "There are no card!" << endl;
        }
    }

    virtual bool IsHitting() const
    {
        const int DecisionPoints = 16;

        return (GetTotal() <= DecisionPoints);
    };

};

