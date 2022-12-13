/*
Quizz 3:
 Write the following program: The user is asked to enter 2 floating point numbers (use doubles). 
 The user is then asked to enter one of the following mathematical symbols: +, -, *, or /. 
 The program computes the answer on the two numbers the user entered and prints the results. 
 If the user enters an invalid symbol, the program should print nothing.
*/

#include <iostream>
#include <string>

int main()
{
    // Get user name
    std::cout << "\nEnter your full name: ";
    std::string name{};
    std::getline(std::cin >> std::ws, name);

    // Get user age
    std::cout << "\nEnter your age: ";
    int age{};
    std::cin >> age;

    // Sum user age and the number of letters in their name
    int letters{static_cast<int>(name.length())};
    std::cout << "Your age + length of name is: " << age + letters << "\n";

    return 0;
}