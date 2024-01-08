/* 
Quizz 1: 
 Write a short program where the user is asked to enter a single character. 
 Print the value of the character and its ASCII code, using static_cast.
*/

#include <iostream>

char getCharFromUser()
{
    char symbol{};
    std::cin >> symbol;

    return symbol;
}

int main()
{
    // Get charachter from user
    std::cout << "\nEnter a single character: ";
    char sym{};
    sym=getCharFromUser();

    // Translate character to ASCII code
    std::cout << "You entered '" << sym << "', which has ASCII code " << static_cast<int>(sym) << "\n";

    return 0;
}