/*
 Quizz 6:
 Write a program that asks the user to input a number between 0 and 255.
 Print this number as an 8-bit binary number (of the form #### ####).
 Don’t use any bitwise operators. Don’t use std::bitset.
*/

#include <iostream>

int getUserValue();

int toBinary(int num);

int main()
{
    // Get user value between 0 and 255
    int num{getUserValue()};
    if (num < 0 || num > 255) // Validate number
        return -1;

    // Convert value to 8-bit binary number
    int numbin{toBinary(num)};

    // Print user value in binary
    std::cout << "Number in binary: 0b" << numbin;

    return 0;
}

// Get user value between 0 and 255
int getUserValue()
{
    std::cout << "Insert value between 0 and 255: ";
    int val{};
    std::cin >> val;

    return val;
}

// Convert value to 8-bit binary number following method 2
int toBinary(int num)
{
    int numbinary{};

    // Bit 7
    if (num >= 128)
    {
        numbinary += 1 * 1000'0000;
        num -= 128;
    }

    // Bit 6
    if (num >= 64)
    {
        numbinary += 100'0000;
        num -= 64;
    }

    // Bit 5
    if (num >= 32)
    {
        numbinary += 10'0000;
        num -= 32;
    }

    // Bit 4
    if (num >= 16)
    {
        numbinary += 1'0000;
        num -= 16;
    }

    // Bit 3
    if (num >= 8)
    {
        numbinary += 1000;
        num -= 8;
    }

    // Bit 2
    if (num >= 4)
    {
        numbinary += 100;
        num -= 4;
    }

    // Bit 1
    if (num >= 2)
    {
        numbinary += 10;
        num -= 2;
    }

    // Bit 0
    if (num >= 1)
    {
        numbinary += 1;
    }

    return numbinary;
}