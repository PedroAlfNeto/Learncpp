/*
 Quizz 7:
 a) Alright, challenge time! Let’s write a simplified version of Blackjack.
 If you’re not already familiar with Blackjack, the Wikipedia article for Blackjack has a summary.

 Start with the code you wrote in quiz #6.
 Create a function named playBlackjack().
 This function should:
    - Accept a shuffled deck of cards as a parameter.
    - Implement Blackjack as defined above (note: you can define other functions to help with this).
    - Returns true if the player won, and false if they lost.
*/

#include "main.hpp"
#include "q6.hpp"   // for card and deck functionality
#include <iostream>
#include <limits>   // for std::numeric_limits
#include <array>
#include <vector>
#include <cassert>

int main()
{
    // Array that represent the deck of cards
    std::array<Card, 52> deck{}; // a deck of cards has 52 cards.

    // Initialize the deck with one of each of its 52 card.
    createDeck(deck);

    // Shuffle deck
    shuffleDeck(deck);

    // DEBUG: Prints the shuffled cards in the deck.
    // printDeck(deck);

    // Play Blackjack
    if(playBlackjack(deck))
    {
        std::cout << "You win!\n";
    }
    else
    {
        std::cout << "You lost...\n";
    }

    // Wait user input before closing terminal
    std::cout << "Press enter to continue";
    std::cin.get();std::cin.get();

    return 0;
}


bool playBlackjack(const std::array<Card, 52>& shuffledDeck)
{
    /* In simplified version of Blackjack, we’re not going to keep track of which specific cards the
        player and the dealer have been dealt with:
            std::vector<Card> dealer_hand{};
            std::vector<Card> player_hand{};
        Instead, only track the sum of the cards they have been dealt.
    */

    // Track the sum of the values of the cards they have been dealt for the player and dealer.
    int player_points{};
    int dealer_points{};

    // Track the dealt card of the shuffled deck for iterating.
    int deck_index{};

    // Initial dealing
    initialDeal(shuffledDeck, deck_index, dealer_points, player_points);

    // User plays
    if(hitOrStand(shuffledDeck, deck_index, player_points))
    {
        // If player busted
        std::cout << "Player busted!\n";
        return false;    // Early return: Lose immediately
    }

    // Dealer counter plays
    if(dealerPlay(shuffledDeck, deck_index, dealer_points))
    {
        // If dealer busted
        std::cout << "Dealer busted!\n";
        return true;    // Early return: Win immediately
    }

    // Compare points
    if(dealer_points > player_points)
    {
        // Player looses with less points
        return false;
    }
    else
    {
        // Player wins with more points
        return true;
    }
}


void initialDeal(const std::array<Card, 52>& deck, int& deckIdx, int& dealerPts, int& playerPts)
{
    // The dealer gets one card to start.
    std::cout << "Dealer:\n";
    dealerPts += dealCard(deck, deckIdx);
    std::cout << "\tDealer points: " << dealerPts << '\n';

    // The player gets two cards to start.
    std::cout << "Player:\n";
    playerPts += dealCard(deck, deckIdx);
    playerPts += dealCard(deck, deckIdx);
    std::cout << "\tPlayer points: " << playerPts << '\n';
}

// Return the card value 
int dealCard(const std::array<Card, 52>& shuffledDeck, int& deck_index)
{
    // Assert whether deck ran out of cards -> should never happen 
    assert(deck_index < 52 && "Deck ran out of cards!");

    std::cout << "\tdrew a ";
    printCard(shuffledDeck[deck_index]);
    std::cout << '\n';

    // Get value of top card in the deck
    int cardValue{getCardValue(shuffledDeck[deck_index])};

    // Iterate to next card for next deal
    ++deck_index;

    return cardValue;
}


bool hitOrStand(const std::array<Card, 52>& shuffledDeck, int& deckIdx, int& playerPts)
{
    // Track player choice for hit or stand
    bool keep_going{reqPlay()};

    // Announce player play and present points
    std::cout << "Player:\n\tPlayer points:" << playerPts << '\n';

    // Play until player stands or busts
    while(keep_going)
    {
        // Give player card
        playerPts += dealCard(shuffledDeck, deckIdx);

        // Print updated player points
        std::cout << "\tPlayer points: " << playerPts << '\n';

        // If player busts
        if(playerPts > 21)
        {
            return true; // Early return with bust
        }

        // Ask player to hit or stand
        keep_going = reqPlay();
    }

    std::cout << "Player stands!\n";
    // Player stand under a score of 21
    return false;
}


bool reqPlay()
{
    int hit{0};

    // Retry until valid input
    while((hit != 1) && (hit != 2))
    {
        std::cout << "Do you hit (1) or stay (2)?: ";

        std::cin >> hit;

        //TODO: Validate input type
        if(std::cin.fail())
        {
            // Clear error flag
            std::cin.clear();

            // Ignore user input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    if(hit == 1)
    {
        // Player chose to hit
        return true;
    }
    else
    {
        // Player chose to stay
        return false;
    }
}


bool dealerPlay(const std::array<Card, 52>& shuffledDeck, int& deckIdx, int& dealerPts)
{
    // Announce dealer play and present points
    std::cout << "Dealer:\n\tDealer points:" << dealerPts << '\n';

    // The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand.
    while(dealerPts < 17)
    {
        // Give dealer a card
        dealerPts += dealCard(shuffledDeck, deckIdx);

        // Print updated dealer points
        std::cout << "\tDealer points: " << dealerPts << '\n';
    }

    // If the dealer goes over a score of 21, they bust and the player wins immediately.
    if(dealerPts > 21)
    {
        return true; // Early return with bust
    }
    else
    {   // Dealer didn't bust
        return false;
    }
}