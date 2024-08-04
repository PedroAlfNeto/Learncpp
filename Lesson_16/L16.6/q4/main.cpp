/*
 Quizz 4:
 Extra credit:
 Modify the prior program so that it can handle a std::vector containing non-int numeric values, 
 such as std::vector arr{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };.
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
int findIndex(std::vector<T>& vec, T val) {
    for (std::size_t idx{0}; idx < vec.size(); ++idx) {
        if (vec.at(idx) == val) {
            return idx;  // return first index found with value
        }
    }

    // Value not found in array
    return -1;  // -1 is not a valid index, so we can use it as an error return
                // value
}

// Passing in low and high allows the compiler to infer the type of the input we want
template <typename T>
T getValue(T low, T high) {
    T user_val{-1};  // incorrect value by default

    std::cout << "Please input an integer number bettwen 1 and 9: ";
    std::cin >> user_val;

    // Repeatedly request value until valid input
    while (user_val < low || user_val > high) {
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
    std::vector arr{4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9};

    // Get user value
    auto val{getValue(1.0, 9.9)};

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