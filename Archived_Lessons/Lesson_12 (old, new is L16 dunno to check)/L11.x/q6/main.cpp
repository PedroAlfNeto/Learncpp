/*
 Quizz 4:
 Let’s pretend we’re writing a card game:

 a) A deck of cards has 52 unique cards (13 card ranks of 4 suits).
    Create enumerations for the card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace)
    and suits (clubs, diamonds, hearts, spades). Those enumerators will not be used to index arrays.

 b) Each card will be represented by a struct named Card that contains a rank and a suit.
    Create the struct.

 c) Create a printCard() function that takes a const Card reference as a parameter and
    prints the card rank and suit as a 2-letter code (e.g. the jack of spades would print as JS).

 d) A deck of cards has 52 cards.
    Create an array (using std::array) to represent the deck of cards, and initialize it with one of
    each card. Do this in a function named createDeck and call createDeck from main.
    createDeck should return the deck to main.
    Hint: Use static_cast if you need to convert an integer into an enumerated type.

 e) Write a function named printDeck() that takes the deck as a const reference parameter and prints
    the cards in the deck. Use a range-based for-loop.
    When you can printDeck with the deck you generated in the previous task, the output should be:
    2C 3C 4C 5C 6C 7C 8C 9C TC JC QC KC AC 2D 3D 4D 5D 6D 7D 8D 9D TD JD QD KD AD 2H 3H 4H 5H 6H 7H
    8H 9H TH JH QH KH AH 2S 3S 4S 5S 6S 7S 8S 9S TS JS QS KS AS
    If you used different characters, that’s fine too.

 f) Write a function named shuffleDeck to shuffle the deck of cards using std::shuffle.
    Update your main function to shuffle the deck and print out the shuffled deck.
    Reminder: Only seed your random number generator once.

 g) Write a function named getCardValue() that returns the value of a Card
    (e.g. a 2 is worth 2, a ten, jack, queen, or king is worth 10. Assume an Ace is worth 11).
*/

#include "main.hpp"
#include <iostream>
#include <cassert>
#include <array>
#include <algorithm> // for std::shuffle
#include <random> // for std::mt19937
#include <ctime>  // std::time

int main()
{
   // Array that represent the deck of cards
   std::array<Card, 52> deck{}; // a deck of cards has 52 cards.

   // Initialize the deck with one of each of its 52 card.
   createDeck(deck);

   // Prints the cards in the deck.
   printDeck(deck);

   // Shuffle deck
   shuffleDeck(deck);
   //std::shuffle(deck.begin(), deck.end(), mt);

   // Prints the shuffled cards in the deck.
   std::cout << '\n';
   printDeck(deck);


   return 0;
}

void printDeck(const std::array<Card, 52>& deck)
{
   for(const Card& card : deck)
   {
      printCard(card);
   }
}


void createDeck(std::array<Card, 52>& deck)
{
   // Counter for iterating through all 52 cards
   int card_cnt{};

   // Iterate through all 4 suits
   for(int suit_cnt{0}; suit_cnt < (static_cast<int>(CardSuit::max_suits)); ++suit_cnt)
   {
      // Iterate through all 3 ranks
      for(int rank_cnt{0}; rank_cnt < (static_cast<int>(CardRank::max_rank)); ++rank_cnt)
      {
         deck[card_cnt].rank = static_cast<CardRank>(rank_cnt);
         deck[card_cnt].suit = static_cast<CardSuit>(suit_cnt);
         ++card_cnt;
      }
   }
}

void printCard(const Card& card)
{
   // Print rank letter
   switch(card.rank)
   {
   case CardRank::rank_2: std::cout << 2; break;
   case CardRank::rank_3: std::cout << 3; break;
   case CardRank::rank_4: std::cout << 4; break;
   case CardRank::rank_5: std::cout << 5; break;
   case CardRank::rank_6: std::cout << 6; break;
   case CardRank::rank_7: std::cout << 7; break;
   case CardRank::rank_8: std::cout << 8; break;
   case CardRank::rank_9: std::cout << 9; break;
   case CardRank::rank_10: std::cout << 10; break;
   case CardRank::rank_jack: std::cout << 'J'; break;
   case CardRank::rank_queen: std::cout << 'Q'; break;
   case CardRank::rank_king: std::cout << 'K'; break;
   case CardRank::rank_ace: std::cout << 'A'; break;
   default:
      assert(!true && "Unhandled card rank");
   }

   // Print card suit letter
   switch(card.suit)
   {
   case CardSuit::clubs: std::cout << 'C'; break;
   case CardSuit::diamonds: std::cout << 'D'; break;
   case CardSuit::hearts: std::cout << 'H'; break;
   case CardSuit::spades: std::cout << 'S'; break;
   default:
      assert(!true && "Unhandled card suit");
   }

   // Add space between cards 
   std::cout << ' ';
}

int getCardValue(const Card& card)
{
   int value{};

   switch(card.rank)
   {
   case CardRank::rank_2:
   case CardRank::rank_3:
   case CardRank::rank_4:
   case CardRank::rank_5:
   case CardRank::rank_6:
   case CardRank::rank_7:
   case CardRank::rank_8:
   case CardRank::rank_9: // Intentional fallthrough
      value = static_cast<int>(card.rank) + 2; // +2 is the ofset between rank enum and value number
      break;
   case CardRank::rank_10:
   case CardRank::rank_jack:
   case CardRank::rank_queen:
   case CardRank::rank_king: // Intentional fallthrough
      value = 10; // a ten, jack, queen, or king is worth 10.
      break;
   case CardRank::rank_ace: // Intentional fallthrough
      value = 11; // an Ace is worth 11
      break;
   default:
      assert(!true && "Unknow card rank to determine value");
   }

   return value;
}

void shuffleDeck(std::array<Card, 52>& deck)
{
   // mt is static so it only gets seeded once.
   static std::mt19937 mt{ std::random_device{}() };

   // Shuffle deck 
   std::shuffle(deck.begin(), deck.end(), mt);
}