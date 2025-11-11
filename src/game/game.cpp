#include "game/game.hpp"
#include <iostream>

using namespace std;

Hand::Hand(bool _isDealer) : isDealer(_isDealer) {}

void Hand::addCard(Card card) {
    hand.emplace_back(card);
}

int Hand::calculateValue() {
    int handValue = 0;
    int aceCount = 0;
    Rank tempRank;

    for(Card card:hand) {
        tempRank = card.getRank();
        // Face cards are worth 10
        if(tempRank == Rank::Jack || 
           tempRank == Rank::Queen || 
           tempRank == Rank::King) {
            handValue += 10;
        }
        // Aces are worth 11 initially (will be reduced to 1 below if needed)
        else if (tempRank == Rank::Ace) {
            handValue += 11;
            aceCount++;
        }
        // Number cards use their enum integer value
        else {
            handValue += static_cast<int>(tempRank);
        }
    }


    while (handValue > 21 && aceCount > 0) 
    {
        handValue -= 10;
        aceCount--;
    }
    

    return handValue;
}

void Hand::displayCards() {
    bool isDealer = getIsDealer();
    bool showAllCards = !isDealer; // Show all cards for player, only first for dealer
    bool firstCard = true;

    for(Card card:hand) {
        if (showAllCards) {
            card.getCard();
        } else {
            // Only show first card, hide others
            if (firstCard) {
                firstCard = false;
                card.getCard();
            } else {
                cout << "[Hidden]";
            }
        }
        std::cout << " "; //space for each card
    }

    std::cout << std::endl;
}

BlackjackGame::BlackjackGame(GameState _turn)
    : turn(_turn), playerHand(false), dealerHand(true) {}

void BlackjackGame::startNewGame() {
    int initialDeal;

    deck.shuffle();
    playerHand.hand.clear();
    dealerHand.hand.clear();

    cout << "Dealing cards..." << endl;

    // Initial deal: two cards each
    for (initialDeal = 0; initialDeal < 4; initialDeal++) {
        if (initialDeal % 2 == 0) {
            playerHand.addCard(deck.dealCard());
        } else {
            dealerHand.addCard(deck.dealCard());
        }
    }
    cout << "Player's cards: ";
    playerHand.displayCards();
    cout << "Dealer's cards: ";
    dealerHand.displayCards();

    turn = GameState::PlayerTurn;
}

void BlackjackGame::playGame() {
    // Player's turn
    cout << "Player's turn." << endl;
    // move(playerHand);

    // // Dealer's turn
    // move(dealerHand);

    // // Determine winner
    // determineWinner();
}

// void BlackjackGame::move(Hand hand) {
//     int choice;
    
//     // Hit or Stand
//     showTurnOptions();
//     choice = getTurnChoice();

//     while(choice == 1) {

//     }

// }