/*
 Quizz 4:
 Okay, time for that game face again. This one is going to be a challenge.
 Let’s rewrite the Blackjack game we wrote in a previous lesson
    (11.x -- Chapter 11 comprehensive quiz) using classes!
 Here’s the full code without classes:

 This Blackjack program is really composed of four parts:
    - the logic that deals with cards,
    - the logic that deals with the deck of cards,
    - the logic that deals with dealing cards from the deck,
    - and the game logic.
 Our strategy will be to work on each of these pieces individually, testing each part with a small
    test program as we go.
 That way, instead of trying to convert the entire program in one go,
    we can do it in 4 testable parts.

 Start by copying the original program into your IDE, and then commenting out everything
    except the #include lines.

 ---------------------------------------------------------------------------------------------------
 d) Next up is the Player.
 Because playerTurn and dealerTurn are very different from each other,
    we’ll keep them as non-member functions.
 - Make Player class and add a drawCard member function that deals the playerone card from the deck,
    increasing the player’s score.
 - We’ll also need a member function to access the Player‘s score.
 - For convenience, add a member function named isBust() that
    returns true if the player’s score exceeds the maximum (g_maximumScore).
*/

#include <algorithm> // std::shuffle
#include <array>
#include <cassert>
#include <ctime> // std::time
#include <iostream>
#include <random> // std::mt19937

class Card
{
public:
    enum Suit
    {
        club,
        diamond,
        heart,
        spade,

        max_suits
    };

    enum Rank
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

        max_ranks
    };

private:
    // private members to hold the rank and suit
    Rank m_rank{};
    Suit m_suit{};

public:
    Card() = default;

    // public default constructor
    Card(Rank rank, Suit suit)
        : m_rank{rank}, m_suit{suit}
    {
    }

    void print() const
    {
        switch (m_rank)
        {
        case Rank::rank_2:
            std::cout << '2';
            break;
        case Rank::rank_3:
            std::cout << '3';
            break;
        case Rank::rank_4:
            std::cout << '4';
            break;
        case Rank::rank_5:
            std::cout << '5';
            break;
        case Rank::rank_6:
            std::cout << '6';
            break;
        case Rank::rank_7:
            std::cout << '7';
            break;
        case Rank::rank_8:
            std::cout << '8';
            break;
        case Rank::rank_9:
            std::cout << '9';
            break;
        case Rank::rank_10:
            std::cout << 'T';
            break;
        case Rank::rank_jack:
            std::cout << 'J';
            break;
        case Rank::rank_queen:
            std::cout << 'Q';
            break;
        case Rank::rank_king:
            std::cout << 'K';
            break;
        case Rank::rank_ace:
            std::cout << 'A';
            break;
        default:
            std::cout << '?';
            break;
        }

        switch (m_suit)
        {
        case Suit::club:
            std::cout << 'C';
            break;
        case Suit::diamond:
            std::cout << 'D';
            break;
        case Suit::heart:
            std::cout << 'H';
            break;
        case Suit::spade:
            std::cout << 'S';
            break;
        default:
            std::cout << '?';
            break;
        }
    }

    int value() const
    {
        switch (m_rank)
        {
        case Rank::rank_2:
            return 2;
        case Rank::rank_3:
            return 3;
        case Rank::rank_4:
            return 4;
        case Rank::rank_5:
            return 5;
        case Rank::rank_6:
            return 6;
        case Rank::rank_7:
            return 7;
        case Rank::rank_8:
            return 8;
        case Rank::rank_9:
            return 9;
        case Rank::rank_10:
            return 10;
        case Rank::rank_jack:
            return 10;
        case Rank::rank_queen:
            return 10;
        case Rank::rank_king:
            return 10;
        case Rank::rank_ace:
            return 11;
        default:
            assert(false && "should never happen");
            return 0;
        }
    }
};

class Deck
{
public:
    // aliases for deck variable types
    using Deck_t = std::array<Card, 52>;
    using Index = Deck_t::size_type;

private:
    Deck_t m_deck{};
    Index m_cardIndex{0};

public:
    // deck constructore
    Deck()
    {
        // card index
        Index index{0};

        for (int suit{0}; suit < static_cast<int>(Card::max_suits); ++suit)
        {
            for (int rank{0}; rank < static_cast<int>(Card::max_ranks); ++rank)
            {
                m_deck[index] = {static_cast<Card::Rank>(rank), static_cast<Card::Suit>(suit)};
                ++index;
            }
        }
    }

    void print()
    {
        for (const auto &card : m_deck)
        {
            card.print();
            std::cout << ' ';
        }

        std::cout << '\n';
    }

    void shuffle()
    {
        static std::mt19937 mt{static_cast<std::mt19937::result_type>(std::time(nullptr))};

        std::shuffle(m_deck.begin(), m_deck.end(), mt);

        // start dealing from the top of the deck again
        m_cardIndex = 0;
    }

    const Card dealCard()
    {
        // validate that index is within deck range
        assert(m_cardIndex < m_deck.size());

        // increment index to next card
        ++m_cardIndex;

        // return current card before increment
        return m_deck[m_cardIndex - 1];
    }
};

constexpr int g_maximumScore{21};

class Player
{
private:
    int m_score{};

public:
    Player()
        : m_score{0}
    {
    }

    int drawCard(Deck &deck)
    {
        // Draw card
        int CardValue = deck.dealCard().value();

        // Update score
        m_score += CardValue;

        return CardValue;
    }

    int score() const
    {
        return m_score;
    }

    bool isBust() const
    {
        return (m_score > g_maximumScore);
    }
};

/*

// Minimum score that the dealer has to have.
constexpr int g_minimumDealerScore{17};


bool playerWantsHit()
{
    while (true)
    {
        std::cout << "(h) to hit, or (s) to stand: ";

        char ch{};
        std::cin >> ch;

        switch (ch)
        {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

// Returns true if the player went bust. False otherwise.
bool playerTurn(const Deck &deck, Index &nextCardIndex, Player &player)
{
    while (true)
    {
        if (player.score > g_maximumScore)
        {
            // This can happen even before the player had a choice if they drew 2
            // aces.
            std::cout << "You busted!\n";
            return true;
        }
        else
        {
            if (playerWantsHit())
            {
                int cardValue{getCardValue(deck.at(nextCardIndex++))};
                player.score += cardValue;
                std::cout << "You were dealt a " << cardValue << " and now have " << player.score << '\n';
            }
            else
            {
                // The player didn't go bust.
                return false;
            }
        }
    }
}

// Returns true if the dealer went bust. False otherwise.
bool dealerTurn(const Deck &deck, Index &nextCardIndex, Player &dealer)
{
    // Draw cards until we reach the minimum value.
    while (dealer.score < g_minimumDealerScore)
    {
        int cardValue{getCardValue(deck.at(nextCardIndex++))};
        dealer.score += cardValue;
        std::cout << "The dealer turned up a " << cardValue << " and now has " << dealer.score << '\n';
    }

    // If the dealer's score is too high, they went bust.
    if (dealer.score > g_maximumScore)
    {
        std::cout << "The dealer busted!\n";
        return true;
    }

    return false;
}

bool playBlackjack(const Deck &deck)
{
    // Index of the card that will be drawn next. This cannot overrun
    // the array, because a player will lose before all cards are used up.
    Index nextCardIndex{0};

    // Create the dealer and give them 1 card.
    Player dealer{getCardValue(deck.at(nextCardIndex++))};

    // The dealer's card is face up, the player can see it.
    std::cout << "The dealer is showing: " << dealer.score << '\n';

    // Create the player and give them 2 cards.
    Player player{getCardValue(deck.at(nextCardIndex)) + getCardValue(deck.at(nextCardIndex + 1))};
    nextCardIndex += 2;

    std::cout << "You have: " << player.score << '\n';

    if (playerTurn(deck, nextCardIndex, player))
    {
        // The player went bust.
        return false;
    }

    if (dealerTurn(deck, nextCardIndex, dealer))
    {
        // The dealer went bust, the player wins.
        return true;
    }

    return (player.score > dealer.score);
}

int main()
{
    auto deck{ createDeck() };

    shuffleDeck(deck);

    if (playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lose!\n";
    }

    return 0;
}
*/

int main()
{
    Deck deck{};

    deck.shuffle();
    deck.print();

    Player player{};
    Player dealer{};

    int playerCard{player.drawCard(deck)};
    std::cout << "The player drew a card with value " << playerCard << " and now has score " << player.score() << '\n';

    int dealerCard{dealer.drawCard(deck)};
    std::cout << "The dealer drew a card with value " << dealerCard << " and now has score " << dealer.score() << '\n';

    return 0;
}