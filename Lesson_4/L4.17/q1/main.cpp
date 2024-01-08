/*
Quizz 1:
 Write a program that asks the user to enter their full name and their age.
 As output, tell the user the sum of their age and the number of letters in the-
 ir name (use the std::string::length() member function to get the length of
 the string).
 For simplicity, count any spaces in the name as a letter.
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