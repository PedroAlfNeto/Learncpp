/*
 Quizz 6 funcions
*/

#include "q6.hpp"
#include <iostream>
#include <cassert>
#include <array>
#include <algorithm> // for std::shuffle
#include <random> // for std::mt19937
#include <ctime>  // std::time

// f) Write a function named shuffleDeck to shuffle the deck of cards using std::shuffle.
//    Update your main function to shuffle the deck and print out the shuffled deck.
void shuffleDeck(std::array<Card, 52>& deck)
{
   // mt is static so it only gets seeded once.
   static std::mt19937 mt{ std::random_device{}() };

    std::shuffle(deck.begin(), deck.end(), mt);
}

/* main function in main.cpp
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

   // Prints the shuffled cards in the deck.
   std::cout << '\n';
   printDeck(deck);


   return 0;
}
*/

void printDeck(const std::array<Card, 52>& deck)
{
   // Iterate though deck printing each card
   for(const Card& card : deck)
   {
      printCard(card);
   }

   // Print new line at the end of the deck
   std::cout << '\n';
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