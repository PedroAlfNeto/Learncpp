/*
 Quizz 1:
 Take the program below and modify it so that the ball falls for as many seconds
 as needed until it reaches the ground.
*/

#include "constants.hpp"
#include <iostream>

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen{myConstants::gravity * seconds * seconds / 2};
    double heightNow{initialHeight - distanceFallen};

    // Check whether we've gone under the ground
    // If so, set the height to ground-level
    if (heightNow < 0.0)
        return 0.0;
    else
        return heightNow;
}

void calculateAndPrintHeight(double initialHeight)
{
    int time_s{};
    double currentHeight {initialHeight};

    while (currentHeight > 0)
    {
        currentHeight = calculateHeight(initialHeight, time_s);
        std::cout << "At " << time_s << " seconds, the ball is at height: "
              << calculateHeight(initialHeight, time_s) << "\n";
        ++time_s;
    }
    
    return;
}

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double initialHeight{};
    std::cin >> initialHeight;

    calculateAndPrintHeight(initialHeight);

    return 0;
}