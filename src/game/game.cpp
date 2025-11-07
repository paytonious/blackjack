#include "game/game.hpp"
#include <iostream>

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
        handValue += static_cast<int>(tempRank);

        if(tempRank == Rank::Ace) {
            aceCount++;
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
    for(Card card:hand) {
        card.getCard();
        std::cout << " "; //space for each card
    }

    std::cout << std::endl;
}