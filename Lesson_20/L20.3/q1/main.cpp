/*
 Quizz 1:

 1 - A factorial of an integer N (written N!) is defined as the product
 (multiplication) of all the numbers between 1 and N (0! = 1). Write a recursive
 function called factorial that returns the factorial of the input. Test it with
 the first 7 factorials.
*/

#include <iostream>

// unoptimized

int factorial(int num) {

    if (num <= 0) {
        return 1;
    }

    return (num * factorial(num - 1));
}

int main() {
    for (int cnt{0}; cnt < 7; ++cnt)
        std::cout << cnt << " factorial is: " << factorial(cnt) << '\n';

    return 0;
}
