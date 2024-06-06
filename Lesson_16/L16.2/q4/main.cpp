/*
 Quizz 4:
 Using a std::vector, write a program that asks the user to enter 3 integral
 values. Print the sum and product of those values.

 The output should match the following:

    Enter 3 integers: 3 4 5
    The sum is: 12
    The product is: 60

*/
#include <iostream>
#include <vector>

int main() {
    std::vector<int> arr(3);
    std::cout << "Enter 3 integers: ";
    std::cin >> arr[0] >> arr[1] >> arr[2];

    std::cout << "The sum is: " << (arr[0] + arr[1] + arr[2]) << '\n';

    std::cout << "The product is: " << (arr[0] * arr[1] * arr[2]) << '\n';

    return 0;
}