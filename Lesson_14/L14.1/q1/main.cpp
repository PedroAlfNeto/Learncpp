/*
 Quizz 1:
    Update the animal procedural example above and instantiate a snake instead of a cat.
*/

#include <iostream>
#include <string_view>

enum AnimalType
{
    cat,
    dog,
    chicken,
    snake, // add new animal type snake
};

constexpr std::string_view animalName(AnimalType type)
{
    switch (type)
    {
    case cat: return "cat";
    case dog: return "dog";
    case chicken: return "chicken";
    case snake: return "snake"; // add name to animal snake
    default:  return "";
    }
}

constexpr int numLegs(AnimalType type)
{
    switch (type)
    {
    case cat: return 4;
    case dog: return 4;
    case chicken: return 2;
    case snake: return 0; // add number of legs to animal snake
    default:  return 0;
    }
}


int main()
{
    constexpr AnimalType animal{ snake }; // instanciate snake instead of cat
    std::cout << "A " << animalName(animal) << " has " << numLegs(animal) << " legs\n";

    return 0;
}