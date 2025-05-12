/*
 Quizz 3:

 We’re going to write a little game with square numbers (numbers which can be
 created by multiplying an integer with itself (1, 4, 9, 16, 25, …)).

    To setup the game:

    Ask the user to enter a number to start at (e.g. 3).
    Ask the user how many values to generate.
    Pick a random integer between 2 and 4. This is the multiplier.
    Generate the number of values the user indicated. Begining with the
starting number, each value should be the next square number, multiplied by the
multiplier.

    To play the game:

    The user enters a guess.
    If the guess matches any generated value, the value is removed from the list
and the user gets to guess again.
    If the user guesses all of the generated values, they win.
If the guess does not match a generated value, the user loses and the program
tells them the nearest unguessed value.

    Tips:

    Use Random.h (8.15 -- Global random numbers (Random.h)) to generate random
numbers. Use std::find() (18.3 -- Introduction to standard library algorithms)
to search for a number in the list. Use std::vector::erase() to remove an
element, e.g. Use std::min_element and a lambda to find the number closest to
the user’s guess. std::min_element works analogous to std::max_element from the
previous quiz.

 [ captureClause ] ( parameters ) -> returnType
    {
        statements;
    }
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "random.h"  // for std::mt19937 and std::random_device

int nearestUnguessed(const int guess, const std::vector<int>& list) {
    int neartValue{*std::min_element(list.begin(), list.end(),
                                     [guess](const int a, const int b) -> bool {
                                         return (std::abs(guess - a) < std::abs(guess - b));
                                     })};
    return neartValue;
}

int main() {
    // Ask the user to enter a number to start at
    int start{};
    std::cout << "Start where?";
    std::cin >> start;  // skip validation

    // Ask the user how many values to generate.
    int size{};
    std::cout << "\nHow many?";
    std::cin >> size;  // skip validation

    // Pick a random integer between 2 and 4.
    const int multiplier{Random::get(1, 4)};

    // Generate list of values
    std::vector<int> values(size);
    for (int idx{}; idx < size; ++idx) {
        values[idx] = (start + idx) * multiplier;
        // Debug
        std::cout << "values[" << idx << "]=" << values[idx] << '\n';
    }

    std::cout << "\nI generated " << size << " square numbers.\n";
    std::cout << "So you know what each number is after multiplying it by "
              << multiplier << "?\n";

    int guess{};
    int nGuessed{};

    for (int idx{}; idx < size; ++idx) {
        std::cin >> guess;

        auto found{std::find(values.begin(), values.end(), guess)};
        if (found != values.end()) {
            ++nGuessed;
            std::cout << "Nice! " << size - nGuessed << " number(s) left.\n";
            values.erase(found);
        } else {
            std::cout << guess << " is wrong! Try "
                      << nearestUnguessed(guess, values) << " next time.\n";
            return 0;  // early return, game lost
        }
    }

    // only reached if all values correctly guessed
    std::cout << "Nice! You found all numbers, good job!";

    return 0;
}