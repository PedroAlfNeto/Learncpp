/*
 Quizz 3:
 Write your own function to swap the value of two integer variables.
 Write a main() function to test it.
*/

#include <iostream>

struct pair
{
    int a{};
    int b{};
};

// Swap two integer variables
void swap_int(pair& numbers)
{
    int tmp{};

    tmp = numbers.a;

    numbers.a = numbers.b;
    numbers.b = tmp;
}

int main()
{
    // Original numbers
    pair my_numbers{1, 2};

    // Swap numbers
    swap_int(my_numbers);

    // Test swapped variables
    std::cout << "First number is:\t" << my_numbers.a << "\nSecond number is:\t" << my_numbers.b << '\n';

    return 0;
}