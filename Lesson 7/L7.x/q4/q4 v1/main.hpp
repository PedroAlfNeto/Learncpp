#ifndef MAIN_HPP
#define MAIN_HPP


// returns true if the user won, false if they lost
bool playGame(int guesses, int number);

bool playAgain();

int getGuess();

bool validateGuess(int guess);

void clearCinBuffer();

#endif