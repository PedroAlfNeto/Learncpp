/*
 Quizz 5:

 Blackjack game

    Extra credit: implement the above two ideas into your blackjack game.
 Note that you will need to show the dealer’s initial card and the player’s
 initial two cards so they know whether they have an ace or not.

    Describe how you could modify the above program to handle the case where
 aces can be equal to 1 or 11.

    In actual blackjack, if the player and dealer have the same score (and the
 player has not gone bust), the result is a tie and neither wins.

    Here’s a sample output:
        The dealer is showing JH (10)
        You are showing AH 7D (18)
        (h) to hit, or (s) to stand: h
        You were dealt JD.  You now have: 18
        (h) to hit, or (s) to stand: s
        The dealer flips a 6C.  They now have: 16
        The dealer flips a AD.  They now have: 17
        You win!
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

struct Player { // struct as still 
    int score{};
    int aces{};

    void drawCard(Deck& deck){
        Card card{deck.dealCard()};
        std::cout << " showing:" << card << "\n";
        std::cout << "You have score:" << score << "\n";
    }

};

namespace Settings {
constexpr int bustScore{21};
constexpr int dealerStopScore{17};
constexpr int gamblerInitCards{2};

}  // namespace Settings

#include <limits>  // for std::numeric_limits

void ignoreLine() {
    // Ignore cin buffer entry
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool continueChoice() {
    char choice{};

    while (true) {
        std::cout << "(h) to hit, or (s) to stand: ";

        // fetch new value
        std::cin >> choice;

        if (choice == 's') {
            return false;  // player stands
        } else if (choice == 'h') {
            return true;  // player hit and continue
        }

        // Ignore cin buffer entry
        ignoreLine();

        // Retry
        std::cout << "Invalid Input!\n(h) to hit, or (s) to stand: ";
    }
}

int accountingAces(Card& card) {
    if (card.value() == Card::Rank::rank_ace) {
        return 1;
    }
    return 0;
}



bool blackjack() {
    Player gambler{};
    Player dealer{};

    Deck deck{};
    deck.shuffle();

    // initial draws
    {
        // Draw dealer card

        // dealer.score += deck.dealCard().value();
        dealer.PlayerDraw(deck);
        // dealer.aces += accountingAces();

        // Draw player cards
        for (int count{}; count < Settings::gamblerInitCards; ++count) {
            // player.score += deck.dealCard().value();
            // player.aces += accountingAces();
        }

        std::cout << "The dealer is showing:" << dealer.score << "\n";
        std::cout << "You have score:" << gambler.score << "\n";
    }

    // player round
    {
        while (continueChoice()) {
            // You were dealt KH.  You now have: 24
            Card latestCard{deck.dealCard()};
            gambler.score += latestCard.value();
            std::cout << "You were dealt " << latestCard
                      << ".  You now have:" << gambler.score << "\n";

            if (gambler.score > Settings::bustScore) {
                std::cout << "You went bust!\n";
                return false;  // gambler looses
            }
        }
    }

    // dealer round
    {
        // The dealer will draw cards until stop score
        while (dealer.score < Settings::dealerStopScore) {
            // Draw dealer card
            Card latestCard{deck.dealCard()};
            dealer.score += latestCard.value();
            // The dealer flips a JS. They now have: 22
            std::cout << "The dealer flips a " << latestCard
                      << ". They now have:" << dealer.score << "\n";
        }
        if (dealer.score > Settings::bustScore) {
            std::cout << "The dealer went bust!\n";
            return true;  // gambler wins
        }
    }

    return (gambler.score > dealer.score);
}

int main() {
    if (blackjack()) {
        std::cout << "You win!";
    } else {
        std::cout << "You lose!";
    }

    return 0;
}