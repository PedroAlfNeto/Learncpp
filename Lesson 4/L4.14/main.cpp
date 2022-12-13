/*
    Test compiler detection of initialized and altered variable in constexpr
    Expect compiler error with -Werror disabled
*/

#include <iostream>

int main()
{
    constexpr double gravity{9.8}; // ok: 9.8 is a constant expression
    constexpr int sum{4 + 5};      // ok: 4 + 5 is a constant expression
    constexpr int something{sum};  // ok: sum is a constant expression

    std::cout << "Enter your age: ";
    int age{5};
    std::cin >> age;

    constexpr int myAge{age}; // compile error: age is not a constant expression

    return 0;
}