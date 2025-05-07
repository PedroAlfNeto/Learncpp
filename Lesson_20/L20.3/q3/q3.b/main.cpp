/*
 Quizz 3:

 3b) Extra credit: Update your code from 3a to handle the case where the user
 may enter 0 or a negative number.

 3b) Extra credit: Update your code from 3a to handle the case where the user
 may enter 0 or a negative number.

 Here’s a sample output (assuming 32-bit integers):
    Enter an integer: -15
    11111111111111111111111111110001
*/

#include <iostream>

void binaryConvert(int num) {
    if (num <= 0) return;  // terminate

    binaryConvert(num / 2);
    std::cout << num % 2;
}

int main() {
    int x;
    std::cout << "Enter a positive integer: ";
    std::cin >> x;

    std::cout << x << " in binary is: ";
    binaryConvert(x);

    return 0;
}
