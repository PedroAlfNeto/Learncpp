/*
 Quizz 1:
 Write a for loop that prints every even number from 0 to 20.
*/

#include <iostream>

int main()
{
    // loop even numbers between 0 and 20
    for (int iii{0}; iii <= 20; iii += 2)
        std::cout << iii << ' ';

    return 0;
}