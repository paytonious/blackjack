#include "card/card.hpp"
#include <iostream>

using namespace std;

Card::Card(Rank rank, Suit suit) : rank_(rank), suit_(suit) {}

void Card::getCard() {
  cout << getRankString() << getSuitString();
}

string Card::getRankString() {
  static const string ranks[] = {
    "", "", "2", "3", "4", "5", "6", "7", 
    "8", "9", "10", "J", "Q", "K", "A"
  };
  return ranks[static_cast<int>(rank_)];
}

string Card::getSuitString() {
  static const string suits[] = {
    "♥", "♦", "♣", "♠"
  };
  return suits[static_cast<int>(suit_)]; 
}

