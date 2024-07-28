/*
 Quizz 1:
 Declare a fixed array with the following names:
    Alex, Betty, Caroline, Dave, Emily, Fred, Greg, and Holly.
 Ask the user to enter a name.
 Use a for each loop to see if the name the user entered is in the array.
*/

#include "main.hpp"
#include <iostream>
#include <string> // for std::string
#include <limits> // for std::numeric_limits

// Requests a name string provides the name back to the input string reference
void getName(std::string& name)
{
    // Request name to user
    std::cout << "Enter a name: ";
    std::getline(std::cin >> std::ws, name); // Get string from user ignoring initial white spaces

    // Retry if failed
    while (std::cin.fail())
    {
        // Clear error flag
        std::cin.clear();

        // Ignore cin buffer entry
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Retry to get name
        std::cout << "Invalid entry\nEnter a name: ";
        std::getline(std::cin >> std::ws, name); // Get string from user ignoring initial white spaces
    }
}

int main()
{
    // Fixed array with name_list
    constexpr std::string_view name_list[]{"Alex", "Betty", "Caroline", "Dave", "Emily", "Fred", "Greg", "Holly"};

    // Get name from User
    std::string name_user; //  std::string as it must be altered in function 
    getName(name_user);

    // Search for input user name in name_list array
    for (std::string_view name : name_list)
    {
        if (name_user == name) // If match is found
        {             
            std::cout << name <<" was found.\n";
            return 0; // early return
        }
    }

    // User input name never found in name_list array
    std::cout << name_user <<" was not found.\n";

    return 0;
}