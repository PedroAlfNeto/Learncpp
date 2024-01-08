/*
 Quizz 4: Extra credit: This one is a little more challenging.
 Write a short program to simulate a ball being dropped off of a tower.
 To start, the user should be asked for the height of the tower in meters.
 Assume normal gravity (9.8 m/s2), and that the ball has no initial velocity (the ball is not moving to start).
 Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds.
 The ball should not go underneath the ground (height 0).
 Use a function to calculate the height of the ball after x seconds.
 The function can calculate how far the ball has fallen after x seconds using the following formula:
    distance fallen = gravity_constant * x_seconds2 / 2
*/

#include <iostream>

double getTowerHeight();

void trackBallDrop(double height);

double calcFreeFall(int sec);

void printBallDrop(double height, int sec, double fall);

int main()
{
    // Get tower height from user
    double h{};
    h = getTowerHeight();

    // Calculate value
    trackBallDrop(h);

    return 0;
}

// Request tower height from user
double getTowerHeight()
{
    double height{};
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> height;

    return height;
}

void trackBallDrop(double height){
    
    double fall{};

    for (int timeS{0};timeS<6;timeS++){
        fall = calcFreeFall(timeS);
        printBallDrop(height, timeS, fall);
    }

    return;
}

double calcFreeFall(int sec){
    constexpr double g{9.8};
    double res{};

    res = g * sec * sec / 2; // distance fallen = gravity_constant * x_seconds2 / 2

    return res;
}

void printBallDrop(double theight, int sec, double fall){
    if (theight > fall)
        std::cout << "At " << sec << " seconds, the ball is at height: "
                  << theight - fall << " meters\n";
    else
        std::cout << "At " << sec << " seconds, the ball is on the ground.";

    return;
}