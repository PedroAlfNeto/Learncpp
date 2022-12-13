/*
 Quizz 1:
 Declare an array to hold the high temperature (to the nearest tenth of a degree) for each day of a
    year (assume 365 days in a year).
Initialize the array with a value of 0.0 for each day.

 Quizz 2:
 Set up an enum with the names of the following animals:
    chicken, dog, cat, elephant, duck, and snake.
 Put the enum in a namespace.
 Define an array with an element for each of these animals, and use an initializer list to
    initialize each element to hold the number of legs that animal has.
 Write a main function that prints the number of legs an elephant has, using the enumerator.
*/

//#include "main.hpp"
#include <iostream>

namespace animals
{
    enum //Mammals // Tip: the name of this enum could be omitted since it isn't used anywhere
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        max_mammals,
    };
};

int main()
{
    using degrees = float;

    // 1) Array to store the maximum temperatures of the day in a year of 365 days;
    degrees maxYearTemps[365]{};
    maxYearTemps[0]+=0;  // for bypassing -Werror of unused variable

    // 2) Array followin enum "animals::mammals" that holds number of legs that animal has
    int animalLegs[animals::max_mammals]{2, 4, 4, 4, 2, 0};
    /*
        animalLegs[animals::chicken]=2;
        animalLegs[animals::dog]=4;
        animalLegs[animals::cat]=4;
        animalLegs[animals::elephant]=4;
        animalLegs[animals::duck]=2;
        animalLegs[animals::snake]=0;
    */

    // Print the number of legs an elephant has, using the enumerator.
    std::cout << "An elephant has " << animalLegs[animals::elephant] << " legs.\n";

    return 0;
}