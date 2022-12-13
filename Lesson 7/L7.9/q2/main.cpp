/*
 Quizz 1:
 Write a function named sumTo() that takes an integer parameter named value, and
 returns the sum of all the numbers from 1 to value.
 For example, sumTo(5) should return 15, which is 1 + 2 + 3 + 4 + 5.

*/

#include "main.hpp" // Revise header files
#include <iostream>

int main()
{
    // Request first integer
    int a{getInteger()};

    // Sum values
    int res{};
    res = sumTo(a);

    // Print result
    std::cout << "The integer sum up to " << a << " is: " << res << '\n';

    return 0;
}

int getInteger()
{
    std::cout << "Enter an integer: ";
    int val{};
    std::cin >> val;

    return val;
}

int sumTo(int value)
{
    int sum{0};

    for (int cnt{1}; cnt <= value; ++cnt)
    {
        sum += cnt;
    }

    return sum;
}