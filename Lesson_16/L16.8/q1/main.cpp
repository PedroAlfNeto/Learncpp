/*
 Quizz 1:
 Define a std::vector with the following names:
    “Alex”, “Betty”, “Caroline”, “Dave”, “Emily”, “Fred”, “Greg”, and “Holly”.
 Ask the user to enter a name.

 Use a range-based for loop to see if the name the user entered is in the array.

*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int main() {
    // name list
    const std::vector<std::string_view> arr{"Alex",  "Betty", "Caroline", "Dave",
                                       "Emily", "Fred",  "Greg",     "Holly"};

    // get user name
    std::cout << "Enter a name: ";
    std::string userName{};
    std::cin >> userName;

    bool found{false};

    // Check if user name is in name list
    for (std::string_view name : arr) {
        if (name == userName) {
            std::cout << userName << " was found.";
            found = true;
            break;  // stop search
        }
    }

    if (!found) {
        std::cout << userName << " was not found.";
    }

    return 0;
}