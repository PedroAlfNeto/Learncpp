// 1- Goal:
//   Calculates the addition of 2 numbers for user
// 2- Requirements:
//   Receive 2 integers from user
//   Calculate user integers sum
//   Provide the user with the 2 integers

#include "io.hpp"

int main()
{
    // Read first value
    int a{readNumber()};

    // Read second value
    int b{readNumber()};

    // Sum user values and print result to user
    writeAwnser(a + b);

    return 0;
}
