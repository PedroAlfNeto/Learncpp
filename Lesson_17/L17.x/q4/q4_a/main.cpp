/*
 Quizz 4:

 Blackjack game

 Create a struct named Player that will represent a participant in our game
 (either the dealer or the player). Since in this game we only care about a
 player’s score, this struct only needs one member.

 Write a function that will (eventually) play a round of Blackjack.
 For now, this function should draw one randomized card for the dealer and two
 randomized cards for the player. It should return a bool value indicating who
 has the greater score.
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
                m_cards[card_idx++] = Card{rank, suit};  // use copy elision
            }
        }
        // Check for array overflow (account for last post decrement)
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

struct Player {
    int score{};
};

bool blackjack() {
    Player player{};
    Player dealer{};

    Deck deck{};
    deck.shuffle();
    
    // Draw dealer card
    dealer.score += deck.dealCard().value();

    // Draw player cards
    player.score += deck.dealCard().value();
    player.score += deck.dealCard().value();

    std::cout << "The dealer is showing:" << player.score << "\n";
    std::cout << "You have score:" << player.score << "\n";

    return (player.score > dealer.score);
}

int main() {
    if (blackjack()) {
        std::cout << "You win!";
    } else {
        std::cout << "You lose!";
    }

    return 0;
}