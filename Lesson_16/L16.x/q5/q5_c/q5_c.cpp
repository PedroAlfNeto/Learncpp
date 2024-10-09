/*
 Question #5
*/

/*
 > Step #3

Now that we can display some game state and get input from the user, let’s
integrate that user input into the game.

Goals:

    Keep track of which letters the user has guessed.
    Display correctly guessed letters.
    Implement a basic game loop.

Tasks:

 Update the Session class to track which letters have been guessed so far.
 Modify the game state function to display both underscores and correctly
    guessed letters.
 Update the input routine to reject letters that have already
    been guessed.
 Write a loop that executes 6 times before quitting (so we can test
    the above).

 In this step, we will not tell the user whether the letter they guessed is in
    the word (but we will show it as part of the game state display).

 The tricky part of this step is deciding how to store information on which
    letters the user has guessed.
 There are several different viable ways to do this.
 A hint: there are a fixed number of letters, and you’re going to be doing this
    a lot.
*/

#include <cassert>
#include <iostream>
#include <limits>
#include <string_view>
#include <vector>

#include "Random.h"

namespace WordList {
const std::vector<std::string_view> word{"mystery",   "broccoli",  "account",
                                         "almost",    "spaghetti", "opinion",
                                         "beautiful", "distance",  "luggage"};

std::string_view getRandomWord() {
    // Get random word from list
    return (word.at(Random::get(0, std::size(word) - 1)));
}
}  // namespace WordList

template <typename T>
bool checkValueinArray(const T& value, const std::vector<T> vec) {
    // Check if value is in the array
    for (const auto& element : vec) {
        if (element == value) return true;  // found
    }

    return false;  // not found
}

// overload for string_view
bool checkValueinArray(const char value, const std::string_view string) {
    // Check if letter is in the string
    for (const auto& element : string) {
        if (element == value) return true;  // found
    }

    return false;  // not found
}

class Session {
   private:
    std::string_view m_word{WordList::getRandomWord()};
    // list of guessed letters (prealocated to supported guesses)
    static constexpr int gameLives{6};

    // track guessed letters
    std::vector<char> m_goodGuesses;
    std::vector<char> m_badGuesses;

    // track game lives
    int m_lives{gameLives};  // start game with full lives

    // track remaining letters to uncover
    int m_missingLetters{static_cast<int>(std::size(m_word))};

    // list of revealed elements in word;
    std::vector<bool> m_revealed;
    // must be initialized by constructor to not confuse compiler with function

    void printGameState() {
        std::cout << "The word: ";

        for (std::size_t idx{0}; idx < std::size(m_word); ++idx) {
            if (m_revealed[idx])
                std::cout << m_word[idx];
            else
                std::cout << '_';
        }

        std::cout << "\tWrong guesses: ";

        // print remaining lives
        for (int cnt{0}; cnt < m_lives; cnt++) std::cout << '+';

        for (const auto& letter : m_badGuesses) std::cout << letter;

        std::cout << '\n';
    }

    bool guessLetter() {
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

            // check if letter already guessed
            if (checkValueinArray(letter, m_goodGuesses) ||
                checkValueinArray(letter, m_badGuesses)) {
                std::cout << "You already guessed that. Try again.\n";
                continue;  // request another letter to user
            };

            /* Check letter */
            bool found{false};

            // Iterate to through word to find occurrences of letter
            for (std::size_t idx{0}; idx < std::size(m_word); ++idx) {
                // letter in word (optimized only check uncovered letters)
                if (letter == m_word[idx]) {
                    if (!found) {  // single found notification
                        found = true;
                        std::cout << "Yes, " << letter
                                  << " is in the word!\n\n";
                        // add letter to guessed list
                        m_goodGuesses.push_back(letter);
                    }

                    // reveal all letter occurences in word
                    m_revealed[idx] = true;

                    --m_missingLetters;  // update missing letters
                }
            }

            if (!found) {
                std::cout << "No, " << letter << " is not in the word!\n\n";
                m_badGuesses.push_back(letter);
            }

            return found;
        }
    }

    // main game loop
    void startGame() {
        std::cout << "Welcome to C++man (a variant of Hangman)\nTo win: guess "
                     "the word.  To lose: run out of pluses.\n\n";

        while (m_missingLetters > 0) {
            printGameState();

            if (guessLetter() == false) {
                // only decrement lives if failed
                --m_lives;
            }

            if (m_lives < 1) {
                std::cout << "You lost!  The word was: " << m_word << '\n';
                return;  // end game
            }
        }
        std::cout << "You win! The word was: " << m_word << '\n';
        return;  // end game
    }

   public:
    // Constructure creates a new game session
    Session()  // Initialize vectors with the specified size
        : m_revealed(std::size(m_word)) {
        // Arrays sizes must match
        assert(std::size(m_revealed) == std::size(m_word));

        startGame();
    }

    // access API (debug only)
    // std::string_view getWord() const { return m_word; }
};

int main() {
    Session gameSession{};

    // std::cout << "DEBUG:The word is: " << gameSession.getWord()
    //           << " - size: " << std::size(gameSession.getWord()) << '\n';

    return 0;
}