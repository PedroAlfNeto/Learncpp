/*
 Quizz 3:
 Given the solution for quiz 2, do the following:

 - Ask the user for a value between 1 and 9.
   If the user does not enter a value between 1 and 9, repeatedly ask for an
 integer value until they do. If the user enters a number followed by extraneous
 input, ignore the extraneous input.

 - Print the array.

 - Write a function template to search the array for the value that the user
 entered. If the value is in the array, return the index of that element. If the
 value is not in the array, return an appropriate value.

 - If the value was found, print the value and index.
   If the value was not found, print the value and that it was not found.

 Here are two sample runs of this program:
    Enter a number between 1 and 9: d
    Enter a number between 1 and 9: 6
    4 6 7 3 8 2 1 9
    The number 6 has index 1

    Enter a number between 1 and 9: 5
    4 6 7 3 8 2 1 9
    The number 5 was not found
*/

#include <iostream>
#include <limits>  // for cin max streamsize
#include <vector>

template <typename T>
void printArray(std::vector<T>& vec) {
    for (std::size_t idx{0}; idx < vec.size(); ++idx) {
        std::cout << vec.at(idx) << ' ';
    }

    if (vec.size() > 0) std::cout << '\n';
}

// Search array for value
template <typename T>
int findIndex(std::vector<T>& vec, int val) {
    for (std::size_t idx{0}; idx < vec.size(); ++idx) {
        if (vec.at(idx) == val) {
            return idx;  // return first index found with value
        }
    }

    // Value not found in array
    return -1;  // -1 is not a valid index, so we can use it as an error return
                // value
}

int getValue(void) {
    int user_val{-1};  // incorrect value by default

    std::cout << "Please input an integer number bettwen 1 and 9: ";
    std::cin >> user_val;

    // Repeatedly request value until valid input
    while (user_val < 1 || user_val > 9) {
        // check invalid input type in cin
        if (std::cin.fail()) {
            std::cin.clear();  // clears error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                            '\n');  // ignores entries in cin buffer
        }

        std::cout << "Invalid input!\nPlease input an integer number bettwen 1 "
                     "and 9: ";
        std::cin >> user_val;
    }

    return user_val;
}

int main() {
    std::vector arr{4, 6, 7, 3, 8, 2, 1, 9};

    // Get user value
    int val{getValue()};

    // Search for user value in index
    int result{findIndex(arr, val)};

    // Print the original array
    printArray(arr);

    if (result >= 0) {
        std::cout << "The number " << val << " has first index " << result;
    } else {
        std::cout << "The number " << val << " was not found";
    }

    return 0;
}