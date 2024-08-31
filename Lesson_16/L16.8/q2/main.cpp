/*
 Quizz 1:
 Modify your solution to quiz 1.

 In this version, create a function template (not a normal function) called
 isValueInArray() that takes two parameters: a std::vector, and a value.

 The function should return true if the value is in the array, and false
 otherwise. Call the function from main() and pass it the array of names and the
 name the user entered.

 Reminder:
    A function template that is using template argument deduction (when template
 type arguments are not explicitly specified) will not do conversions to match
 the template type parameters. The call either matches the template (and the
 template type can be deduced) or it doesn’t. A function template with an
 explicitly specified template type argument will convert arguments to match the
 parameter type (since the type is known).

*/

#include <iostream>
#include <string>
#include <string_view>
#include <vector>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& val) {
    // Check if value is in the array
    for (const auto& item : arr) {
        if (val == item) {
            return true;
        }
    }

    return false;
}

int main() {
    // name list
    const std::vector<std::string_view> arr{"Alex",  "Betty", "Caroline", "Dave",
                                       "Emily", "Fred",  "Greg",     "Holly"};

    // get user name
    std::cout << "Enter a name: ";
    std::string userName{};
    std::cin >> userName;

    // explicitly specify std::string_view to function template
    const bool found{isValueInArray<std::string_view>(arr, userName)};

    if (found) {
        std::cout << userName << " was found.";
    } else {
        std::cout << userName << " was not found.";
    }

    return 0;
}