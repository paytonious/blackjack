#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

#include "card/card.hpp"
#include "deck/deck.hpp"

enum class GameState {
    InitialDeal,
    PlayerTurn,
    DealerTurn,
    GameEnd,
};

class Hand {
    public:
        std::vector<Card> hand;

        Hand(bool _isDealer);
        void addCard(Card card);
        int calculateValue();
        void displayCards();

        bool getIsDealer() {return isDealer;}
    private:
        bool isDealer;
};

class BlackjackGame {
    public:
        Deck deck;
        Hand playerHand;
        Hand dealerHand;
        GameState turn;

    private:
};

#endif