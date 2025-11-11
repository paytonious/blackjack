#include <iostream>
#include <vector>

#include "card/card.hpp"
#include "deck/deck.hpp"
#include "game/game.hpp"

using namespace std;

int main() {
  const int TWO_CONST = 2;

  BlackjackGame game;
  game.startNewGame();
  game.playGame();

  return 0;
}

