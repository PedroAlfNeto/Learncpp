/*
 Quizz 2:
 Write a function named findValue that takes a pointer to the beginning and
    a pointer to the end (1 element past the last) of an array, as well as a value.
 The function should search for the given value and return a pointer to the first element with that
    value, or the end pointer if no element was found.

*/

//#include "main.hpp"
#include <iostream>
#include <iterator>

// ...

int* findValue(int* prt_start, int* ptr_end, int target_val)
{
    for (int* ptr_search = prt_start; ptr_search < ptr_end; ptr_search++)
    {
        if (*ptr_search == target_val)
        {
            // Early return with address of the first element with target value 
            return ptr_search;
        }
    }

    // Did not find target value in given address range
    return ptr_end;
}

int main()
{
    int arr[]{ 2, 5, 4, 10, 8, 20, 16, 40 };

    // Search for the first element with value 20.
    int* found{ findValue(std::begin(arr), std::end(arr), 20) };

    // If an element with value 20 was found, print it.
    if (found != std::end(arr))
    {
        std::cout << *found << '\n';
    }
    else
    {
        std::cout << "Did not find value in array.\n";
    }

    return 0;
}