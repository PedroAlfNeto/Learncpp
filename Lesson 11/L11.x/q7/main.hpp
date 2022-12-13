/*
 Serves as template
*/

#ifndef MAIN_HPP    // Header guard
#define MAIN_HPP

#include "q6.hpp"

// Play blackjack game, returning true if player wins
bool playBlackjack(const std::array<Card, 52>& deck);

// Deal card returning its value
int dealCard(const std::array<Card, 52>& shuffledDeck, int& deck_index);

// Initial dealings
void initialDeal(const std::array<Card, 52>& shuffledDeck, int& deckIdx, int& dealerPts, int& playerPts);

// User plays: return true if busted
bool hitOrStand(const std::array<Card, 52>& shuffledDeck, int& deckIdx, int& playerPts);

// Request user whether to hit or stand
bool reqPlay();

// Dealer draws cards: return true if busted
bool dealerPlay(const std::array<Card, 52>& shuffledDeck, int& deckIdx, int& dealerPts);

#endif