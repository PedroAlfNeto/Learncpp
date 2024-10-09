/*
 Quizz 2:
 Initialize a std::array with the following values: ‘h’, ‘e’, ‘l’, ‘l’, ‘o’.
 Print the value of the element with index 1.
*/

#include <array>
#include <iostream>

int main() {
    constexpr std::array<char, 5> hello{'h', 'e', 'l', 'l', 'o'};

    std::cout << hello[1];

    return 0;
}