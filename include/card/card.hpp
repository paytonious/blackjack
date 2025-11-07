#ifndef CARD_HPP
#define CARD_HPP
#include <string>

enum class Suit {
    Hearts, Diamonds, Clubs, Spades
};

enum class Rank {
    Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten,
    Jack = 10, Queen = 10, King = 10, Ace = 11
};

class Card {
public:
    Card(Rank rank, Suit suit);
    void getCard();
    std::string getRankString();
    std::string getSuitString();
    
    Rank getRank() const { return rank_; }
    Suit getSuit() const { return suit_; }
    
private:
    Rank rank_;
    Suit suit_;
};

#endif // !CARD_HPP
