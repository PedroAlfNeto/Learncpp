/*
 Quizz 1:
 Write a function to print a C-style string character by character.
 Use a pointer and pointer arithmetic to step through each character of the
    string and print that character.
 Write a main function that tests the function with the string literal “Hello,
 world!”.
*/

#include <iostream>

// v1 pedro, not exactly pointer arithmetic...
//  void printCString(const char str[]) {
//      constexpr int KStringLenMax{255};

//     for (int idx{0}; idx < KStringLenMax; ++idx) {  // limit len to 256 chars
//         // Check for null terminator
//         if (str[idx] == '\0') {
//             return;  // end of string
//         } else {
//             std::cout << str[idx];
//         }
//     }

//     std::cout << "Error! Overflown";
// }

void printCString(const char *str) { // or 
    int overflowDetect{255};
    while (*str != '\0') {
        std::cout << *str; // print character

        ++str;

        if (--overflowDetect < 0) {  // limit len to 256 chars
            std::cout << "Error! Overflown";
            return;
        }
    }
    return;  // end of string
}

int main() {
    const char string[]{"Hello, world!"};

    printCString(string);  // C-style string will decay to pointer

    return 0;
}