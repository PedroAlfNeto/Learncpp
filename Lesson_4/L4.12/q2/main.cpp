/*
Quizz 2:
 Modify the program you wrote for quiz #1 to use implicit type conversion inste-
 ad of static_cast.
 How many different ways can you think of to do this?
*/

#include <iostream>

int getCharFromUser()
{
    char symbol{};
    std::cin >> symbol;

    std::cout << "You entered '" << symbol;

    return symbol;
}

int main()
{
    // Get charachter from user
    std::cout << "\nEnter a single character: ";
    int sym{};
    sym = getCharFromUser();

    // Translate character to ASCII code
    std::cout << "', which has ASCII code " << sym << "\n";

    return 0;
}