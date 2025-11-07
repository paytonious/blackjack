#ifndef DECK_HPP 
#define DECK_HPP

#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <thread>
#include <stdexcept>

#include "card/card.hpp"

class Deck {
  public:
    Deck();
    void shuffle();
    Card dealCard();
    void printDeck();
    bool isEmpty();

  private:
    std::vector<Card> cards_;
};

#endif // !DEBUG
