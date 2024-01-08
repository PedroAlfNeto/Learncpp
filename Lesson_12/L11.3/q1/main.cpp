/*
 Quizz 1:
 Print the following array to the screen using a loop:
 constexpr int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };

 Hint: You can use std::size (as of C++17) or the sizeof() trick (prior to C++17) to determine the array length.
*/

//#include "main.hpp"
#include <iostream>

int main()
{
    constexpr int array[]{4, 6, 7, 3, 8, 2, 1, 9, 5};

    std::cout << "array[" << std::size(array) << "]:{";

    for (int i = 0; i < static_cast<int>(std::size(array)); i++)
    {
        std::cout << array[i];
        if(i<static_cast<int>(std::size(array))-1) std::cout << ", ";
    }

    std::cout << "}\n";

    return 0;
}

/*
void print_array(const int my_array[9])
{
    std::cout << "array[" << std::size(my_array) << "]:{";

    for (int i = 0; i < static_cast<int>(std::size(my_array)); i++)
    {
        std::cout << my_array[i];
        if(i<static_cast<int>(std::size(my_array))-1) std::cout << ", ";
    }

    std::cout << "}\n";
}
*/