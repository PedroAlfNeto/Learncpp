/*
 Quizz 2:

 Write a recursive function that takes an integer as input and returns the sum
 of each individual digit in the integer (e.g. 357 = 3 + 5 + 7 = 15).
 Print the answer for input 93427 (which is 25). Assume the input values are
 positive.
*/

#include <iostream>

int digitSum(int num) {
    if (num < 10) {
        std::cout << ' ' << num << " = ";
        return num;
    }
    std::cout << num % 10 << " + ";  // debug

    return (num % 10 + digitSum(num / 10));
}

int main() {
    std::cout << digitSum(93427);

    return 0;
}
