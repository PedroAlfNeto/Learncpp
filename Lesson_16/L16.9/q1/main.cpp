/*
 Quizz 1:
 Create a program-defined enum (inside a namespace) containing the names of the
 following animals: chicken, dog, cat, elephant, duck, and snake.

 Define an array with an element for each of these animals, and use an
 initializer list to initialize each element to hold the number of legs that
 animal has.

 Assert that the array has the correct number of initializers.

 Write a main() function that prints the number of legs an elephant has, using
 the enumerator.
*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <cassert>

namespace Animals {
enum Animals : unsigned int {
    chicken,     // 0
    dog,         // 1
    cat,         // 2
    elephant,    // 3
    duck,        // 4
    snake,       // 5
    max_animals  // 6
};
const std::vector legs{2, 4, 4, 4, 2, 0};
}  // namespace Animals

int main() {
    assert(std::size(Animals::legs) == Animals::max_animals "assert");

    std::cout << "The elephant has " << Animals::legs[Animals::elephant] << "legs.\n";

    return 0;
}