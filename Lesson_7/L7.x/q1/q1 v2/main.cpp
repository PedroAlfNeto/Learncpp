/*
 Quizz 1:
 Take the program below and modify it so that the ball falls for as many seconds
 as needed until it reaches the ground.
*/

#include <iostream>
#include "constants.hpp"

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

int main()
{
    std::cout << "Enter the initial height of the tower in meters: ";
    double aux;
    std::cin >> aux;
    const double initialHeight{aux};
    double currentHeight{initialHeight};

    for (int time_s {0}; currentHeight > 0; ++time_s)
    {
        currentHeight= calculateHeight(initialHeight,time_s);
        std::cout << "At " << time_s << " seconds the ball is at height: " << currentHeight << "\n";
    }
    
    return 0;
}