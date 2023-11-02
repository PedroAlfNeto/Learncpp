/*
 Quizz 2:
 Given the array in question 1:
 Ask the user for a number between 1 and 9.
 If the user does not enter a number between 1 and 9, repeatedly ask for an integer value until they do.
 Once they have entered a number between 1 and 9, print the array.
 Then search the array for the value that the user entered and print the index of that element.
*/

//#include "main.hpp"
#include <iostream>
#include <limits> // for cin max streamsize

// Get user number between 1 and 9.
int getValue();

void print_array(const int my_array[9]);

int main()
{
    constexpr int array[]{4, 6, 7, 3, 8, 2, 1, 9, 5};

    // Ask the user for a number between 1 and 9
    int value{getValue()};

    // Print array
    print_array(array);

    // Search for user value in array at index provided by user
    int value_index{};
    for (int i = 0; i < static_cast<int>(std::size(array)); i++)
    {
        if (value == array[i])
        {
            value_index = i;
            break; // break for cycle
        }
    }

    // Print the index of the user value
    std::cout << "The number " << value << " has index " << value_index << '\n';

    // E.g. "The number 6 has index 1"

    return 0;
}

int getValue()
{
    int user_val{};

    std::cout << "Please input an integer number bettwen 1 and 9: ";
    std::cin >> user_val;

    // Repeatedly request value until valid input
    while (user_val < 1 || user_val > 9)
    {
        // check invalid input type in cin
        if (std::cin.fail())
        {
            std::cin.clear();                                                   // clears error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignores entries in cin buffer
        }

        std::cout << "Invalid input!\nPlease input an integer number bettwen 1 and 9: ";
        std::cin >> user_val;
    }

    return user_val;
}

void print_array(const int my_array[9])
{
    std::cout << "array[" << 9 << "]:{";

    for (int i = 0; i < 9; i++)
    {
        std::cout << my_array[i];
        if (i < 9 - 1)
            std::cout << ", ";
    }

    std::cout << "}\n";
}