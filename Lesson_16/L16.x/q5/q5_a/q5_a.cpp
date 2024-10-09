/*
 Question #5

 Let’s implement the game C++man (which will be our version of the classic
 children’s lynching game Hangman.

 In case you’ve never played it before, here are the abbreviated rules:

 High level:

  The computer will pick a word at random and draw an underscore for each letter
 in the word. The player wins if they guess all the letters in the word before
 making X wrong guesses (where X is configurable).

 Each turn:

  The player will guess a single letter.
  If the player has already guessed that letter, it doesn’t count, and play
 continues. If any of the underscores represent that letter, those underscores
 are replaced with that letter, and play continues. If no underscores represent
 that letter, the player uses up one of their wrong guesses.

 Status:

  The player should know how many wrong guesses they have left.
  The player should know what letters they have guessed incorrectly (in
 alphabetical order).

 Because this is C++man, we’ll use a + symbol to indicate the number of wrong
 guesses left. If you run out of + symbols, you lose.
*/

/*
 > Step #1

    Goals:

    We’ll start by defining our list of words and writing a random word picker.
    You can use the Random.h from lesson 8.15 (Random.h) to assist.

    Tasks:

    First define a namespace named WordList.
    The starter list of words is: “mystery”, “broccoli” , “account”, “almost”,
    “spaghetti”, “opinion”, “beautiful”, “distance”, “luggage”.

    You can add others if you like.
    Write a function to pick a random word and display the word picked. Run the
program several times to make sure the word is randomized.

Here is a sample output from this step:
*/

#include <iostream>
#include <limits>
#include <string_view>
#include <vector>

#include "Random.h"

namespace WordList {
constexpr int maxWords{8};
const std::vector<std::string_view> word{"mystery",   "broccoli",  "account",
                                         "almost",    "spaghetti", "opinion",
                                         "beautiful", "distance",  "luggage"};

std::string_view getRandomWord() {
    // Get random word from list
    return (word.at(Random::get(0, WordList::maxWords)));
}

}  // namespace WordList

int main() {
    std::vector<int> user_vec{};

    std::cout << "Welcome to C++man (a variant of Hangman)\nTo win: guess the "
                 "word.  To lose: run out of pluses.\n";

    std::cout << "The word is: " << WordList::getRandomWord();

    return 0;
}