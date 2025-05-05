/*
 Quizz 3:
 Let’s say we want to write a card game that uses a standard deck of cards. In
 order to do that, we’re going to need some way to represent those cards, and
 decks of cards. Let’s build that functionality.

 We’ll use it in the next quiz question to actually implement a game.
*/

/*
> Step #1

 A deck of cards has 52 unique cards (13 card ranks of 4 suits).
 Create enumerations for the card ranks (ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, jack,
queen, king) and suits (clubs, diamonds, hearts, spades).

> Step #2
 Each card will be represented by a struct named Card that contains a rank and a
suit member. Create the struct and move the enums into it.

*/

#include <array>
#include <iostream>

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

int main() {
    // Print one card
    Card card{Card::rank_5, Card::suit_heart};
    std::cout << card << '\n';

    // Print all cards
    for (auto suit : Card::allSuits)
        for (auto rank : Card::allRanks) std::cout << Card{rank, suit} << ' ';
    std::cout << '\n';

    return 0;
}