/*
 Quizz 3:
 Let’s say we want to write a card game that uses a standard deck of cards. In
 order to do that, we’re going to need some way to represent those cards, and
 decks of cards. Let’s build that functionality.

 We’ll use it in the next quiz question to actually implement a game.
*/

/*
> Step #4

 Next, let’s create our deck of cards.
 Create a class named Deck that contains a std::array of Cards.
 You can assume a deck is 52 Cards.

 The Deck should have three functions:
 -First, the default constructor should initialize the array of cards.
 You can use a ranged-for loop similar to the one in the main() function of the
prior example to traverse through all the suits and ranks.
 -Second, add a dealCard() function that returns the next card in the Deck by
value. Since std::array is a fixed-size array, think about how you will keep
track of where the next card is. This function should assert out if it is called
when the Deck has gone through all the cards.
 - Third, write a shuffle() member function that shuffles the deck.
 To make this easy, we will enlist the help of std::shuffle:
*/

#include <algorithm>  // for std::shuffle
#include <array>
#include <cassert>
#include <iostream>

#include "Random.h"  // for Random::mt


struct Card {
    enum Suit {
        suit_club,
        suit_diamond,
        suit_heart,
        suit_spade,

        max_suits
    };

    enum Rank {
        rank_ace,
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

        max_ranks
    };
    /*
    > Step #3

    Next, let’s add some useful functions to our Card struct. First, overload
    operator<< to print the card rank and suit as a 2-letter code (e.g. the jack
    of spades would print as JS).
    You can do that by completing the following function:

    Second, add a function that returns the value of the Card. Treat an ace as
    value 11.

    Finally, add a std::array of Rank and of Suit (named allRanks and
    allSuits respectively) so they can be iterated over.
    Because these are part of a struct (not a namespace), make them static so
    they are only instantiated once (not with each object).

    */

    // These need to be static so they are only created once per program, not
    // once per Card
    static constexpr std::array allRanks{
        rank_ace, rank_2, rank_3,  rank_4,    rank_5,     rank_6,   rank_7,
        rank_8,   rank_9, rank_10, rank_jack, rank_queen, rank_king};
    static constexpr std::array allSuits{suit_club, suit_diamond, suit_heart,
                                         suit_spade};
    static_assert(allRanks.size() == max_ranks && "Invalid size of allRanks");
    static_assert(allSuits.size() == max_suits && "Invalid size of allSuits");

    Rank rank{};
    Suit suit{};

    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        static constexpr std::array ranks{'A', '2', '3', '4', '5', '6', '7',
                                          '8', '9', 'T', 'J', 'Q', 'K'};
        static constexpr std::array suits{'C', 'D', 'H', 'S'};
        static_assert(ranks.size() == max_ranks && "Invalid size of ranks");
        static_assert(suits.size() == max_suits && "Invalid size of suits");
        out << ranks[card.rank] << suits[card.suit];
        return out;
    }

    int value() const {
        static constexpr std::array rankValues{11, 2, 3,  4,  5,  6, 7,
                                               8,  9, 10, 10, 10, 10};
        static_assert(rankValues.size() == max_ranks &&
                      "Invalid size of rankValues");

        return rankValues[rank];
    }
};

class Deck {
   private:
    static constexpr std::size_t kdeck_size{52};
    std::array<Card, kdeck_size> m_cards{};
    std::size_t m_nextCard{};

   public:
    Deck() {
        std::size_t card_idx{0};
        // Initialize Deck
        for (auto suit : Card::allSuits) {
            for (auto rank : Card::allRanks) {
                m_cards[card_idx++] = Card{rank, suit}; // use copy elision
            }
        }
        //Check for array overflow (account for last post decrement)
        assert(card_idx <= kdeck_size && "Deck overflow at init!");
    }

    Card dealCard() {
        assert(m_nextCard < kdeck_size && "No cards left in the deck!");
        return m_cards[m_nextCard++];  // return card with post decrement
    };

    void shuffle() {
        // Put this line in your shuffle function to shuffle m_cards using the
        // Random::mt Mersenne Twister This will rearrange all the Cards in the
        // deck randomly
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    }
};

int main() {
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' '
              << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' '
              << deck.dealCard() << '\n';

    return 0;
}