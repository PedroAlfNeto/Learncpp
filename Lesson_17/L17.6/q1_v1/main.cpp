/*
 Quizz 1:
 Define a namespace named Animal.
 Inside it, define an enum containing the following animals:
    chicken, dog, cat, elephant, duck, and snake.

 Also create a struct named Data to store each animal’s name, number of legs,
 and the sound it makes.

 Create a std::array of Data and fill out a Data element for each animal.

 Ask the user to enter the name of an animal.
 If the name does not match the name of one of our animals, tell them so.
 Otherwise, print the data for that animal.
 Then print the data for all of the other animals that didn’t match their input.
*/

#include <array>
#include <cassert>
#include <iostream>
#include <string_view>

namespace Animal {

enum Type {
    chicken,    // 0
    dog,        // 1
    cat,        // 2
    elephant,   // 3
    duck,       // 4
    snake,      // 5
    max_animal  // 6
};

struct Data {
    std::string_view name{};
    int legs{};
    std::string_view sound{};
};

using namespace std::string_view_literals;  // for sv suffix for CTAD

[[maybe_unused]] constexpr std::array data{
    Data{"chicken"sv, 2, "cluck"sv}, Data{"dog"sv, 4, "woof"sv},
    Data{"cat"sv, 4, "meow"sv},      Data{"elephant"sv, 4, "pawoo"sv},
    Data{"duck"sv, 2, "quack"sv},    Data{"snake"sv, 0, "hissss"sv},
};

static_assert(data.size() == max_animal);

// Teach operator>> how to input a Animal by name
// We pass animal by non-const reference so we can have the function modify its
// value
std::istream& operator>>(std::istream& in, Animal::Type& animal) {
    std::string input{};
    std::getline(in >> std::ws, input);

    // Iterate through the list of names to see if we can find a matching name
    for (std::size_t index = 0; index < max_animal; ++index) {
        if (input == data[index].name) {
            // If we found a matching name, we can get the enumerator value
            // based on its index
            animal = static_cast<Animal::Type>(index);
            return in;
        }
    }

    // We didn't find a match, so input must have been invalid
    // so we will set input stream to fail state
    in.setstate(std::ios_base::failbit);

    // On an extraction failure, operator>> zero-initializes fundamental types
    // Uncomment the following line to make this operator do the same thing
    // color = {};
    return in;
}

}  // namespace Animal

int main() {
    std::cout << "Enter an animal: ";
    Animal::Type userAnimal{
        Animal::max_animal};  // invalid default for iteration loop

    std::cin >> userAnimal;

    // Tell user that input does not match the name of one of our animals
    if (!std::cin) {
        std::cout << "That animal couldn't be found.\n\n";
    } else {
        std::cout << "A " << Animal::data[userAnimal].name << " has "
                  << Animal::data[userAnimal].legs << " legs and says "
                  << Animal::data[userAnimal].sound << ".\n\n";
    }

    std::cout << "Here is the data for the rest of the animals:\n";

    for (std::size_t idx{}; idx < Animal::data.size(); ++idx) {
        if (idx == userAnimal) continue;
        // skip already user animal if presented

        std::cout << "A " << Animal::data[idx].name << " has "
                  << Animal::data[idx].legs << " legs and says "
                  << Animal::data[idx].sound << ".\n";
    }

    return 0;
}