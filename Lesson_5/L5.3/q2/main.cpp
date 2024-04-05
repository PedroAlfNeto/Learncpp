/*
 Quizz 2:
 Write a program that asks the user to enter their full name and their age.
 As output, tell the user the sum of their age and the number of letters in the-
 ir name (use the std::string::length() member function to get the length of
 the string).
 For simplicity, count any spaces in the name as a letter.
*/

#include <iostream>

bool isEven(int num);

int main()
{
    // Get user name
    std::cout << "\nEnter an integer: ";
    int val{};
    std::cin >> val;

    if (isEven(val))
        std::cout << val << " is even\n";
    else
        std::cout << val << " is odd\n";



    return 0;
}

bool isEven(int num){
    int remainder{};
    remainder = num%2;

    // Alternative with casting
    //bool even = !static_cast<bool>(remainder);

    return (remainder == 0);
}