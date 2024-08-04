/*
 Quizz 3:
 Modify the following program so that instead of having maxScore hold the largest score directly,
    a variable named maxIndex holds the index of the largest score.
 The program should still print the largest score.
*/

#include <iostream>
#include <iterator> // for std::size

int main()
{
    constexpr int scores[]{84, 92, 76, 81, 56};

    // Old variable
    // int maxScore{ 0 }; // Assume our largest score is 0 to start

    // Hold the index of student with the maximum score
    int maxIndex{0};

    // now look for a larger score in the full array
    for (int student{0}; student < static_cast<int>(std::size(scores)); ++student)
    {
        if (scores[student] > scores[maxIndex])
        {
            maxIndex = student;
        }
    }

    std::cout << "The best score was " << scores[maxIndex] << '\n';

    return 0;
}