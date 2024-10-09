/*
 Quizz 1:
 Complete the following program:
    main function

 When run, it should print:

    The array (1, 4, 9, 16) has length 4
    The array (h, e, l, l, o) has length 5

*/

#include <array>
#include <iostream>

template <typename T, auto N>
void printArray(const std::array<T, N>& arr) {
    bool first{true};

    std::cout << "The array (";
    for (const auto& element : arr) {
        if (!first) std::cout << ", "; // dont print comma before first element
        std::cout << element;
        first = false;
    }

    std::cout << ") has length " << std::size(arr) << '\n';
}

int main() {
    constexpr std::array arr1{1, 4, 9, 16};
    printArray(arr1);

    constexpr std::array arr2{'h', 'e', 'l', 'l', 'o'};
    printArray(arr2);

    return 0;
}