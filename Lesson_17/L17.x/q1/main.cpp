/*
 Quizz 1:
 What’s wrong with each of these snippets, and how would you fix it?
*/

// a) <'=' std::size(arr) is  out of bounds
/*
#include <array>
#include <iostream>

int main()
{
    std::array arr { 0, 1, 2, 3 };

    for (std::size_t count{ 0 }; count < std::size(arr); ++count)
    {
        std::cout << arr[count] << ' ';
    }

    std::cout << '\n';

    return 0;
}
*/

// b) range based for loop has no way of no way of knowing size of C-style
// array. Also it decays to pointer when passed to function, so std::size()
// would not work. Needs additional parameter

// or use std::array ;p

/*
#include <iostream>

void printArray(int array[], int size) {
    // for (int element : array)
    // {
    //     std::cout << element << ' ';
    // }

    for (int idx{}; idx < size; ++idx) {
        std::cout << array[idx] << ' ';
    }
}

int main() {
    int array[]{9, 7, 5, 3, 1};

    printArray(array, std::size(array));

    std::cout << '\n';

    return 0;
}
*/

// c) size of std::array must be known at compile time (constexpr)
// use std::vector instead

// #include <array>
#include <iostream>
#include <vector>


int main() {
    std::cout << "Enter the number of test scores: ";
    std::size_t length{};
    std::cin >> length;

    [[maybe_unused]] std::vector<int> scores(length);

    for (std::size_t i{0}; i < length; ++i) {
        std::cout << "Enter score " << i << ": ";
        std::cin >> scores[i];
    }

    return 0;
}