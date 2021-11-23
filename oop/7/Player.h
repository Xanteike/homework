#pragma once

#include "GenericPlayer.h"

class Player : public GenericPlayer
{
public:
    Player(const string& name) :
        GenericPlayer(name)
    {}

    virtual bool IsHitting() const override
    {
        char c = GetUserInput<char>(name + ", do you want to take a card?");
        return (c=='y' || c=='Y');
    };

    void Win() const { cout << name + " win!!!" << endl; }
    void Lose() const { cout << name + " lose!!!" << endl; }
    void Push() const { cout << "drow!!!" << endl; }
};

