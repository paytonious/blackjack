#include "deck/deck.hpp"
#include "card/card.hpp"
#include <algorithm>
#include <chrono>
#include <random>
#include <stdexcept>
#include <iostream>
#include <thread>

Deck::Deck() {
  // Rank enum assigns specific point values (e.g. Jack/Queen/King = 10, Ace = 11)
  // so their underlying integer values are not necessarily contiguous.
  // Iterate an explicit list of Rank values to reliably build the 52-card deck.
  for (int suit = static_cast<int>(Suit::Hearts);
       suit <= static_cast<int>(Suit::Spades);
       ++suit) {
    for (Rank rank : { Rank::Two, Rank::Three, Rank::Four, Rank::Five,
                       Rank::Six, Rank::Seven, Rank::Eight, Rank::Nine,
                       Rank::Ten, Rank::Jack, Rank::Queen, Rank::King,
                       Rank::Ace }) {
      cards_.emplace_back(rank, static_cast<Suit>(suit));
    }
  }
}

void Deck::shuffle() {
   unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
   std::default_random_engine rng(seed);
   std::shuffle(cards_.begin(), cards_.end(), rng);
}

Card Deck::dealCard() {
  if(isEmpty()) {
    throw std::runtime_error("Deck is empty");
  }

  Card deltCard = cards_.back();
  cards_.pop_back();
  return deltCard;
}

void Deck::printDeck() {
  for(auto& card : cards_) {
    card.getCard();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << std::endl;
  }
}

bool Deck::isEmpty() {
  return cards_.empty();
}
