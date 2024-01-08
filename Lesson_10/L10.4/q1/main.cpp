/*
 Quizz 1:
 1)Define an enum class named Animal that contains the following animals:
    pig, chicken, goat, cat, dog, duck.
 2)Write a function named getAnimalName() that takes an Animal parameter and uses a switch statement
    to return the name for that animal as a std::string_view (or std::string if you’re using C++14).
 3)Write another function named printNumberOfLegs() that uses a switch statement to print the number
    of legs each animal walks on.
 4)Make sure both functions have a default case that prints an error message.
 5)Call printNumberOfLegs() from main() with a cat and a chicken.
 Your output should look like this:
    A cat has 4 legs.
    A chicken has 2 legs.
*/

//#include "main.hpp"
#include <iostream>
#include <string_view> // for std::string_view
#include <cassert> 

// 1) enum class named Animal that contains animals
namespace animals
{
    enum class Animal
    {
        pig,
        chicken,
        goat,
        cat,
        dog,
        duck,
    };
}

// 2) function getAnimalName() that takes an Animal to return the name for that animal
constexpr std::string_view getAnimalName(animals::Animal animal)
{
    using namespace animals;
    // std::string_view animal_name{};

    switch (animal)
    {
    case (Animal::pig):
        // animal_name = "pig";
        return "pig";
    case (Animal::chicken):
        return "chicken";
    case (Animal::goat):
        return "goat";
    case (Animal::cat):
        return "cat";
    case (Animal::dog):
        return "dog";
    case (Animal::duck):
        return "duck";
    default: // Reached in case of invalid input
        std::cerr << "Invalid animal!";
        std::abort();
        break;
    }
    // return ;
}

// 3) function printNumberOfLegs() that uses a switch statement to print the number of legs each animal walks on.
void printNumberOfLegs(animals::Animal animal)
{
    using namespace animals;
    // std::string_view animal_name{};

    switch (animal)
    {
    // intentional fallthrough
    case (Animal::pig):
    case (Animal::goat):
    case (Animal::cat):
    case (Animal::dog):
        std::cout << "A " << getAnimalName(animal) << " has 4 legs.\n";
        return;
    // intentional fallthrough
    case (Animal::chicken):
    case (Animal::duck):
        std::cout << "A " << getAnimalName(animal) << " has 2 legs.\n";
        return;
    // Reached in case of invalid input
    default:
        std::cerr << "Invalid animal!";
        assert(!true && "Should have been validated previously");
        std::abort();
        break;
    }
}

int main()
{
    printNumberOfLegs(animals::Animal::cat);
    printNumberOfLegs(animals::Animal::chicken);
    return 0;
}