/*
 Quizz 1:
 Convert the following std::array definition to an equivalent constexpr C-style
 array definition:
*/

// #include <array>
// constexpr std::array<int, 3> a{}; // allocate 3 ints
constexpr int array[3]{};

/*
 Quizz 2:
 What three things are wrong with the following program?

 1) initializing a C-style array with lvalue (does not support dynamic initialization)
 2) assessing out of bounds lengh=5, arr[length] is forbidden (permited 0-4)
    - undefined behaviour 
 3) const type array cant have element value reassigned
*/

#include <iostream>

int main()
{
    int length{ 5 };
    const int arr[length] { 9, 7, 5, 3, 1 }; // allowed? maybe compile extensions not disabled

    std::cout << arr[length];
    arr[0] = 4;

    return 0;
}