/*
 Quizz 3:
 Invert the nested loops example so it prints the following:
 5 4 3 2 1
 4 3 2 1
 3 2 1
 2 1
 1
*/

#include <iostream>

int main()
{
    // outer loops between 5 and 1
    int outer{5};
    while (outer >= 1)
    {
        // For each iteration of the outer loop, the code in the body of the loop executes once

        // inner loops between outer and 1
        int inner{outer};
        while (inner >= 1)
        {
            std::cout << inner << ' ';
            --inner;
        }

        // print a newline at the end of each row
        std::cout << '\n';
        --outer;
    }

    return 0;
}