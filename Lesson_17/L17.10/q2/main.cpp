/*
 Quizz 3:
 Repeat quiz #1, but this time the function should print the string backwards.
*/

#include <iostream>

// v1 pedro not using a pointer copy
/*
void printReverseCString(const char *str) {  // or
    int overflowDetect{255};
    int stringLen{};

    // traverse to end of string and determine lenght
    while (*str != '\0') {
         std::cout << *str;
        ++stringLen;
        ++str;
        if (--overflowDetect < 0) {  // limit len to 256 chars
            std::cout << "Error! Overflown";
            return;
        }
    }

    std::cout << '\n';
    --str; // decrement null terminator position

    // print string backwards
    while (stringLen > 0) {
        std::cout << *str;  // print character
        --str;
        --stringLen;
    }
    return;  // end of string
}
*/

// v2 using a pointer copy (error prone IMO with value specific while break)
void printReverseCString(const char str[]) {
      int overflowDetect{255};
    const char* ptrCpy{str};

    // traverse to end of string
    while (*ptrCpy != '\0') {
        std::cout << ptrCpy;
        ptrCpy++;

        if (--overflowDetect < 0) {  // limit len to 256 chars
          std::cout << "Error! Overflown";
          return;
        }
    }
    
    std::cout << '\n';

    while (ptrCpy-- != str) { // post decrement required to print last char
        std::cout << *ptrCpy;  // print value
    }
}

int main() {
    const char string[]{"Hello, world!"};

    printReverseCString(string);  // C-style string will decay to pointer
    return 0;
}