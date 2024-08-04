/*
 Quizz 6:
 In the quiz for lesson 8.10 -- For statements, we implemented a game called
 FizzBuzz for the numbers three, five, and seven.

 In this quiz, implement the game as follows:

    Numbers divisible by only 3 should print “fizz”.
    Numbers divisible by only 5 should print “buzz”.
    Numbers divisible by only 7 should print “pop”.
    Numbers divisible by only 11 should print “bang”.
    Numbers divisible by only 13 should print “jazz”.
    Numbers divisible by only 17 should print “pow”.
    Numbers divisible by only 19 should print “boom”.
    Numbers divisible by more than one of the above
        should print each of the words associated with its divisors.
    Numbers not divisible by any of the above should just print the number.

 Use a std::vector to hold the divisors,
    and another std::vector to hold the words (as type std::string_view).

 If the arrays do not have the same length, the program should assert.
 Produce output for 150 numbers.

*/

#include <cassert>
#include <iostream>
#include <string_view>
#include <vector> //V1
#include <array>

void fizzbuzz(int max) {
    /* 
    //V1
    // single initialization (std::vector doesnt support constexpr)
    static const std::vector<int> divisors{3, 5, 7, 11, 13, 17, 19};
    static const std::vector<std::string_view> words{
        "fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};
        
    assert(divisors.size() == words.size() &&
           "arrays do not have the same length!");
    */

    //v2  preferable to use a constexpr std::array here instead. 
    constexpr std::array divisors{3, 5, 7, 11, 13, 17, 19};
    constexpr const std::array words{"fizz", "buzz", "pop", "bang", "jazz", "pow", "boom"};

    // iterate through natural numbers up to max
    for (int idxNum{1}; idxNum <= max; ++idxNum) {
        bool divided{false};

        // iterate through divisors
        for (std::size_t idxDiv{0}; idxDiv < divisors.size(); ++idxDiv) {
            if (!(idxNum % divisors.at(idxDiv))) {  
                std::cout << words.at(idxDiv); // divisible by divisor
                divided = true;
            }
        }

        if (!divided) std::cout << idxNum;

        std::cout << '\n';
    }
}

int main() {
    fizzbuzz(150);

    return 0;
}
