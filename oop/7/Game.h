#pragma once

class Game
{
public:
    Game(const vector<string>& names)
    {
        for (const auto& pName : names) {
            players.emplace_back(Player(pName));
        }

        deck.Populate();
        deck.Shuffle();
    }

    ~Game() {};

    void Play();

private:
    Deck deck;
    House house;
    vector<Player> players;
};

inline void Game::Play()
{
    const int MinimumPlayersIncludeDealer = 2;

    for (int i = 0; i < MinimumPlayersIncludeDealer; ++i) {
        for (auto& pPlayer: players) {
            deck.Deal(pPlayer);
        }
        deck.Deal(house);
    }

    house.OpenFirstCard();

    for (const auto& pPlayer: players) {
        cout << pPlayer << endl;
    }
    cout << house << endl;

    for (auto& pPlayer: players) {
        deck.AdditionalCards(pPlayer);
    }

    house.OpenFirstCard();
    cout << endl << house;

    deck.AdditionalCards(house);

    if (house.IsBusted()) {
        for (auto& pPlayer: players) {
            if (!(pPlayer.IsBusted())) {
                pPlayer.Win();
            }
        }
    } else {
        for (auto& pPlayer: players) {
            if (!(pPlayer.IsBusted())) {
                if (pPlayer.GetTotal() > house.GetTotal()) {
                    pPlayer.Win();
                } else if (pPlayer.GetTotal() < house.GetTotal()) {
                    pPlayer.Lose();
                } else {
                    pPlayer.Push();
                }
            }
        }

    }

    for (auto& pPlayer: players) {
        pPlayer.Clear();
    }
    house.Clear();
}
