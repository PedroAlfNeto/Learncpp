/*
 Quizz 5:
 Modify the FizzBuzz program you wrote in the previous quiz to add the rule that
 numbers divisible by seven should be replaced with “pop”. Run the program for
 150 iterations.

 In this version, using an if/else chain to explicitly cover every possible
 combination of words will result in a function that is too long. Optimize your
 function so only 4 if-statements are used: one for each of the non-compound
 words (“fizz”, “buzz”, “pop”), and one for the case where a number is printed.
*/

#include <iostream>

void fizzbuzz(int max) {
    for (int idx{1}; idx <= max; ++idx) {
        bool divided{false};

        if (!(idx % 3)) {  // divisible by 3
            std::cout << "fizz";
            divided = true;
        }

        if (!(idx % 5)) {  // divisible by 5
            std::cout << "buzz";
            divided = true;
        }

        if (!(idx % 7)) {  // divisible by 5
            std::cout << "pop";
            divided = true;
        }

        if (!divided) std::cout << idx;

        std::cout << '\n';
    } // for loop
}

int main() {
    fizzbuzz(150);

    return 0;
}
