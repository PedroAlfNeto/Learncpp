/*
 Question #5

*/

/*
 > Step #2

 As we develop complex programs, we want to work incrementally, adding one or
 two things at a time and then making sure they work. What makes sense to add
 next?

 Goals:

    Be able to draw the basic state of the game, showing the word as
    underscores. Accept a letter of input from the user, with basic error
    validation.

 In this step, we will not yet keep track of which letters the user has entered.

 Here is the sample output from this step:

    Welcome to C++man (a variant of Hangman)
    To win: guess the word.  To lose: run out of pluses.

    The word: ________
    Enter your next letter: %
    That wasn't a valid input.  Try again.
    Enter your next letter: a
    You entered: a

 Tasks:

    - Create a class named Session that will be used to store all of the data
 the game needs to manage in a game session.
 For now, we just need to know what the random word is.

    - Create a function to display the basic state of the game, where the word
 is displayed as underscores.

    - Create a function to accept a letter of input from the user.
    Do basic input validation to filter out non-letters or extraneous input.
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

class Session {
   private:
    std::string_view m_word{WordList::getRandomWord()};

   public:
    // Constructure creates a new game session
    Session() {
        std::cout
            << "Welcome to C++man (a variant of Hangman)\nTo win: guess the "
               "word.  To lose: run out of pluses.\n";
    }

    void printGameState() {
        std::cout << "The word: ";

        // print dashes for letters in word
        for (std::size_t counter{}; counter < m_word.size(); ++counter) {
            std::cout << '_';
        }

        std::cout << '\n';
    }

    char getLetter() {
        char letter{};
        while (true) {
            std::cout << "Enter your next letter: ";
            std::cin >> letter;

            if (std::cin.fail() || letter < 'a' ||
                letter > 'z')  // handle bad input
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                std::cout << "\nThat wasn't a valid input.  Try again.\n";
                continue;  // restart loop
            }

            // return validated letter
            return letter;
        }
    }

    // access API
    std::string_view getWord() const { return m_word; }
};

int main() {
    Session gameSession{};

    std::cout << "DEBUG:The word is: " << gameSession.getWord()
              << " - size: " << std::size(gameSession.getWord()) << '\n';

    gameSession.printGameState();

    char letter{gameSession.getLetter()};
    std::cout << "\nYou entered: " << letter;

    return 0;
}