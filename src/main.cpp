#include <iostream>
#include <vector>

#include "card/card.hpp"
#include "deck/deck.hpp"
#include "game/game.hpp"

using namespace std;

int main() {
  const int TWO_CONST = 2;

  Deck deck;
  vector<Card> dealerHand;
  vector<Card> playerHand;
  Hand playerHandTest(false);

  cout << "Let's play Blackjack!" << endl;
  cout << endl << "shuffling cards test" << endl;
  deck.shuffle(); 

  cout << endl << "dealing cards" << endl;
  for (int i = 0; i < 2; i++) {
    playerHandTest.addCard(deck.dealCard());
  }
  cout << playerHandTest.calculateValue() << " ";
  playerHandTest.displayCards();

  return 0;
}

