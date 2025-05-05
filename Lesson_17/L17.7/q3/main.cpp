/*
 Quizz 3:
 A “perfect square” is a natural number whose square root is an integer.
 We can make perfect squares by multiplying a natural number (including zero) by
    itself.
 The first 4 perfect squares are: 0, 1, 4, 9.

 Use a global constexpr C-style array to hold the perfect squares between 0 and
    9 (inclusive).
 Repeatedly ask the user to enter a single digit integer, or -1 to quit.

 Print whether the digit the user entered is a perfect square.

 Hints: Use a range-based for loop to traverse the C-style array to look for
    a match.
*/

#include <array>
#include <iostream>
#include <limits>  // for cin max streamsize

// { 0, 1, 2, 3, 4 , 5 , 6 , 7 , 8 , 9  }
// { 0, 1, 4, 9, 16, 25, 36, 49, 64, 81 }
constexpr int perfect_squares[]{0, 1, 4, 9};

int getValue(void) {
    int user_val{};  // incorrect value by default

    std::cout << "Enter a single digit integer, or -1 to quit: ";
    std::cin >> user_val;

    // Repeatedly request value until valid input
    while (user_val < -2 || user_val > 9) {
        // check invalid input type in cin
        if (std::cin.fail()) {
            std::cin.clear();  // clears error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                            '\n');  // ignores entries in cin buffer
        }

        std::cout << "\nInvalid input!\nPlease input an integer number bettwen 1 "
                     "and 9, or -1 to quit: ";
        std::cin >> user_val;
    }
    return user_val;
}

int main() {
    int value{};
    bool squared{};

    while (value != -1) {
        value = getValue();
        squared = false;  // reset

        // check if value is perfect square
        for (auto element : perfect_squares) {
            if (value == element) {
                std::cout << value << " is a perfect square\n";
                squared = true;
                break;  // stop search
            }
        }

        if (!squared) std::cout << value << " is not a perfect square\n";
    }

    std::cout << "Bye\n";

    return 0;
}