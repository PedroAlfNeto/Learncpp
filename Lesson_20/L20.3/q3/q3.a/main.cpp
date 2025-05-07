/*
 Quizz 1:

3a) This one is slightly trickier. Write a program that asks the user to enter a
positive integer, and then uses a recursive function to print out the binary
representation for that number. Use method 1 from lesson O.4 -- Converting
integers between binary and decimal representation.

Hint: Using method 1, we want to print the bits in reverse order.
This means your print statement should be after the recursive call.
*/

#include <iostream>

// h/t to reader Gapo for this solution
void printBinary(int x) {
    // Termination case
    if (x == 0) return;

    // Recurse to the next bit
    printBinary(x / 2);

    // Print out the remainders (in reverse order)
    std::cout << x % 2;
}

int main() {
    int x;
    std::cout << "Enter a positive integer: ";
    std::cin >> x;

    printBinary(x);
}