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
    // Construct game and ensure hands are created with correct isDealer flags
    // playerHand will be initialized with isDealer = false
    // dealerHand will be initialized with isDealer = true
    BlackjackGame(GameState _turn = GameState::InitialDeal);
        Deck deck;
        Hand playerHand;
        Hand dealerHand;
        GameState turn;

        void startNewGame();
        void playGame();

    private:
        void determineWinner();
        void move(Hand hand);
        void showTurnOptions();
        int getTurnChoice();
};

#endif