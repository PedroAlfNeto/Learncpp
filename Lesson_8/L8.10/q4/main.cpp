/*
 Quizz 4:
 Fizz Buzz is a simple math game used to teach children about divisibility.
 It is also sometimes used as an interview question to assess basic programming
 skills.

 The rules of the game are simple:
    - Starting at 1, and counting upward,
    - replace any number divisible only by three with the word “fizz”,
    - any number only divisible by five with the word “buzz”,
    - and any number divisible by both 3 and 5 with the word “fizzbuzz”.

 Implement this game inside a function named fizzbuzz() that takes a parameter
 determining what number to count up to. Use a for-loop and a single if-else
 chain (meaning you can use as many else-if as you like).
*/

#include <iostream>

void fizzbuzz(int max) {
    for (int idx{1}; idx <= max; ++idx) {

        if(!(idx % 3) && !(idx % 5)){ // divisible by 3 and 5
            std::cout << "fizzbuzz\n";
        }
        else if(!(idx % 3)){ // divisible only by 3
            std::cout << "fizz\n";
        }
        else if(!(idx % 5)){ // divisible only by 5
            std::cout << "buzz\n";
        }   
        else{
            std::cout << idx << '\n';
        }
    }
}

int main() {
    fizzbuzz(15);

    return 0;
}
