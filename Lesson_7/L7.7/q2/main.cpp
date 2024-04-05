/*
 Quizz 2:
 Write a program that prints out the letters a through z along with their ASCII codes.
*/

#include "main.hpp" // Revise header files
#include <iostream>

int main()
{
    // loop counter
    int cnt{asciiconsts::fistletter};

    while (cnt <= asciiconsts::lastletter)
    {
        std::cout << "Letter " << static_cast<char>(cnt) << " in ASCII number " << cnt << '\n';  
        ++cnt;
    }

    std::cout << "Finished the alphabet!";

    return 0;
}
