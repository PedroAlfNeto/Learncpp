/*
 Quizz 1:
 Write a program that asks the user to enter two integers, one named smaller, the other named larger.
 If the user enters a smaller value for the second integer, use a block and a temporary variable to
   swap the smaller and larger values.
 Then print the values of the smaller and larger variables.
 Add comments to your code indicating where each variable dies.
 Note: When you print the values, smaller should hold the smaller input and larger the larger input,
 no matter which order they were entered in.
*/

#include "main.hpp" // Revise header files
#include <iostream>

int main()
{
    // Request two integers
    std::cout << "Enter an integer: ";
    int smaller{catchInteger()}; // smaller enters scope and is created here

    std::cout << "Enter a larger integer: ";
    int larger{catchInteger()}; // larger enters scope and is created here

    // sort variables
    if (smaller > larger)
    {
        std::cout << "Swapping the values\n";
        int tmpsort{smaller}; // tmpsort enters scope and is created here
        smaller = larger;
        larger = tmpsort;
    } // tmpsort goes out of scope and is destroyed here
    else if (smaller == larger)
    {
        std::cout << "The numbers are equal!";
        return 0;
    }

    // tmpsort;    //test block scope

    // print results
    printResults(larger, smaller);

    return 0;
} // smaller and larger go out of scope and are destroyed here

int catchInteger()
{
    int val{};
    std::cin >> val;

    return val;
}

void printResults(int l, int s)
{
    std::cout << "The smaller value is " << s << "\nThe larger value is " << l;
}