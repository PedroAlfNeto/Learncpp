/*
 Quizz 1:
 Write a program that:
 - Asks the user how many names they wish to enter.
 - Dynamically allocates a std::string array.
 - Asks the user to enter each name.
 - Calls std::sort to sort the names
 - Prints the sorted list of names.
*/

#include "main.hpp"
#include <iostream>
#include <string>    // for std::string
#include <algorithm> // for std::sort

int main()
{
    // Asks the user how many names they wish to enter
    int list_size{reqUserNameNum()};

    // Dynamically allocate a std::string array.
    auto name_list{new std::string[list_size]{}};

    name_list[0] = "testing"; // ignore unused variable werror

    // Ask the user to enter each name.
    getnames(name_list, list_size);

    // Sort the names
    // std::sort(name_list, name_list + list_size);
    std::sort(name_list, name_list);

    // Prints the sorted list of names.
    print_name_list(name_list, list_size);

    // Deallocate memory
    delete[] name_list;
    name_list = nullptr; // redundant here as it is going out of scope, but good practice otherwise

    return 0;
}

int reqUserNameNum()
{
    // Variable to hold number of names to be added to the list
    int names_num{};

    // Request number of names to add
    std::cout << "How many names would you like to enter? ";
    std::cin >> names_num;

    // Receive and validate input
    while (std::cin.fail())
    {
        // Clear cin error flag
        std::cin.clear();

        // Ignore cin buffer entry
        std::cin.ignore(buffer_op::max, '\n');

        // Retry
        std::cout << "Invalid input! How many names would you like to enter? ";
        std::cin >> names_num;
    }

    // Ignore cin buffer entry (NEED TO FIGURE WHY THIS IS NEEDED HERE!!!)
    // std::cin.ignore(buffer_op::max, '\n');

    return names_num;
}

void getnames(std::string name_list[], const int list_size)
{
    // Fill list with names from the user
    for (int cnt{}; cnt < list_size; cnt++)
    {
        // Receive and validate input
        std::cout << "Enter name #" << cnt + 1 << ": ";
        std::getline(std::cin >> std::ws, name_list[cnt]);

        while (std::cin.fail())
        {
            // Clear cin error flag
            std::cin.clear();

            // Ignore cin buffer entry
            std::cin.ignore(buffer_op::max, '\n');

            // Retry to receive valid name from user
            std::cout << "Enter name #" << cnt + 1 << ": ";
            std::getline(std::cin >> std::ws, name_list[cnt]);
        }

        std::cout << "Name accepted\n";
    }
}

void print_name_list(const std::string name_list[], const int list_size)
{
    std::cout << "Here is your sorted list:\n";
    for (int cnt_name{0}; cnt_name < list_size; ++cnt_name)
    {
        std::cout << "Name #" << cnt_name << ": " << name_list[cnt_name] << '\n';
    }
}