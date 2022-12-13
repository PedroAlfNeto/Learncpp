/*
 Quizz 1:
 Implement a game of hi-lo. First, your program should pick a random integer between 1 and 100.
 The user is given 7 tries to guess the number.

 If the user does not guess the correct number, the program should tell them whether they guessed
 too high or too low.
 If the user guesses the right number, the program should tell them they won.
 If they run out of guesses, the program should tell them they lost, and what the correct number is.
 At the end of the game, the user should be asked if they want to play again.
 If the user doesn’t enter ‘y’ or ‘n’, ask them again.

 For this quiz, assume the user enters a valid number.
 Use a Mersenne Twister PRNG, and seed it using a std::seed_seq with 8 results from std::random_device.
*/

#include "main.hpp"
#include <iostream>
#include <random> // for std::mt19937 and std::random_device
#include <cassert>

int main()
{
    bool game{true}; // To decide wether to start the game, first game always yest

    // Loop for playing game until user decides not to
    while (game)
    {
        // run hi-low
        hiloGame();

        // Replay question
        game = askReplay();
    }

    return 0;
}

void hiloGame()
{
    // Random number between 1 and 100
    const int luckyNum{prng1to100()};
    // std::cout << "\nCHEAT: Random number is: " << luckyNum << '\n'; // cheating only

    int guess{}; // player guess

    std::cout << "Guess what is your lucky number between 100 and 1!\nTake a guess: ";

    // Provide 7 guesses
    for (int remGuess{7}; remGuess > 0; --remGuess)
    {
        std::cin >> guess;

        if (guess == luckyNum)
        {
            // Game lost as guesses ended
            std::cout << "You win!!!\n";
            return; // early return for winner
        }
        else if (guess < luckyNum)
        {
            std::cout << "Nhee too low... " << remGuess - 1 << " guesses remaining!\nTake another guess: ";
        }
        else if (guess > luckyNum)
        {
            std::cout << "Uff TOO HIGH!!! " << remGuess - 1 << " guesses remaining!\nTake another guess: ";
        }
    }

    // Game lost as guesses ended
    std::cout << "You loose! The lucky number was: " << luckyNum << '\n';
}


// WRONG TO INITIALIZE PRNG MULTIPLE TIME IN THE PROGRAM!! SHOULD ONLY BE DONE ONCE!! AND THEN CALL die100(mt)
// generate random number with Mersenne Twister PRNG between 1 and 100
int prng1to100()
{
    // get 8 integers of random numbers from std::random_device for the seed
    std::random_device rd;
    std::seed_seq seed8{rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()};

    // Initialize Mersenne Twister PRNG with seed
    std::mt19937 mt{seed8};

    // Create a reusable random number generator that generates uniform numbers between 1 and 6
    std::uniform_int_distribution die100{1, 100};

    return (die100(mt));
}

bool askReplay()
{
    // player choice for replaying hi-lo game
    char choice{};

    // infinite loop until valid getting a valid option
    while ((choice != 'n') && (choice != 'y'))
    {
        std::cout << "Play again? Enter 'y' for yes and 'n' for no: ";
        std::cin >> choice;

        switch (choice)
        {
        case 'y':
            // if y, breakes inner loop and replays
            return true;
        case 'n':
            return false;
        default: // in case of any other character
            std::cout << choice << " in an invalid character!\n";
            break;
        }
    }

    // never reached
    assert(!true && "End of askReplay() should never have been reached");
    return false;
}