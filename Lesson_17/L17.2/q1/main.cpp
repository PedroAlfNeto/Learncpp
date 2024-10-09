/*
 Quizz 1:
 Initialize a std::array with the following values: ‘h’, ‘e’, ‘l’, ‘l’, ‘o’.
 Print the length of the array, and then use operator[], at() and std::get() to
 print the value of the element with index 1.
*/

#include <array>
#include <iostream>

int main() {
    constexpr std::array<char, 5> hello{'h', 'e', 'l', 'l', 'o'};

    std::cout << "The length is " << std::ssize(hello) << '\n';
    std::cout << hello[1] << hello.at(1) << std::get<1>(hello);

    return 0;
}