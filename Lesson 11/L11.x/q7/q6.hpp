/*
 Header for quizz 6 funcions
*/

#ifndef Q6_HPP    // Header guard
#define Q6_HPP

#include <array>

//  6)a) A deck of cards has 52 unique cards (13 card ranks of 4 suits).
//     Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace)
//     and suits (clubs, diamonds, hearts, spades). Those enumerators will not be used to index arrays.
enum class CardRank
{
   rank_2,
   rank_3,
   rank_4,
   rank_5,
   rank_6,
   rank_7,
   rank_8,
   rank_9,
   rank_10,
   rank_jack,
   rank_queen,
   rank_king,
   rank_ace,
   max_rank
};
enum class CardSuit
{
   clubs,
   diamonds,
   hearts,
   spades,
   max_suits
};

// 6)b) Each card will be represented by a struct named Card that contains a rank and a suit.
//     Create the struct.
struct Card
{
   CardRank rank{};
   CardSuit suit{};
};


// 6)e) Write a function named printDeck() that takes the deck as a const reference parameter and prints
//    the cards in the deck. Use a range-based for-loop.
void printCard(const Card& card);

// 6)d) A deck of cards has 52 cards.
//    Create an array (using std::array) to represent the deck of cards, and initialize it with one of
//    each card. Do this in a function named createDeck and call createDeck from main.
//    createDeck should return the deck to main.
//    Hint: Use static_cast if you need to convert an integer into an enumerated type.
void createDeck(std::array<Card, 52>& deck);

// 6)c) Create a printCard() function that takes a const Card reference as a parameter and
//     prints the card rank and suit as a 2-letter code (e.g. the jack of spades would print as JS).
void printDeck(const std::array<Card, 52>& deck);

// f) Write a function named shuffleDeck to shuffle the deck of cards using std::shuffle.
//    Update your main function to shuffle the deck and print out the shuffled deck.
void shuffleDeck(std::array<Card, 52>& deck);

// 6)g) Write a function named getCardValue() that returns the value of a Card
//    (e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10. Assume an Ace is worth 11).
int getCardValue(const Card& card);



#endif