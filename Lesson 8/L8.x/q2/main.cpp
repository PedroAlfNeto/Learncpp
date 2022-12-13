/*
 Quizz 2a:
 2a) Upgrade the following program using type aliases:
*/

//#include "main.hpp"
#include <iostream>

using Degrees = double;
using Radians = double;

namespace constants
{
    inline constexpr double pi { 3.14159 };
}

Radians convertToRadians(Degrees degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    Degrees degrees{};
    std::cin >> degrees;

    Radians radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}