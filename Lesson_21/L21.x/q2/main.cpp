/*
 Quizz 2:

 Write a class named Average that will keep track of the average of all integers
 passed to it. Use two members: The first one should be type std::int32_t, and
 used to keep track of the sum of all the numbers you’ve seen so far. The second
 should keep track of how many numbers you’ve seen so far. You can divide them
 to find your average.

 a) Write all of the functions necessary for the following main program to run,
 and produce the result:

    0
    4
    6
    12
    6.5
    7
    7

*/
/*
b) Should you provide a user-defined copy constructor or assignment operator for this class?
   A: No because shallow-copy is correct here as there is no dynamic memory management.

c) Why use std::int32_t instead of int?
    A: int may be 16bit wide on some platforms, total sum can overflow, enforcing
    a 32bit size prevents this I gues... dumb question at this stage

*/

#include <iostream>

class Average {
   private:
    std::int32_t element_sum{};
    int element_num{};

    double getAverage() const {
        // prevent division by zero
        if (element_num < 1) {
            return 0;
        }

        return (static_cast<double>(element_sum) / element_num);
    }

   public:
    // default constructor is fine;

    friend std::ostream& operator<<(std::ostream& out, const Average& avg);

    Average& operator+=(int num){
        element_sum+=num;
        ++element_num;

        // enable chaining operator chaining
        return *this;
    }
};

std::ostream& operator<<(std::ostream& out, const Average& avg) {
    out << avg.getAverage();
    return out;
}

int main() {
    Average avg{};
    std::cout << avg << '\n';

    avg += 4;
    std::cout << avg << '\n'; // 4 / 1 = 4

    avg += 8;
    std::cout << avg << '\n'; // (4 + 8) / 2 = 6

    avg += 24;
    std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

    avg += -10;
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

    (avg += 6) += 10; // 2 calls chained together
    std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

    Average copy{ avg };
    std::cout << copy << '\n';

    return 0;
}
