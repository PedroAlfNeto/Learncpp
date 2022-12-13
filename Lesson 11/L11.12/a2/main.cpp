/*
 Test array dynamic allocation
*/

//#include "main.hpp"
#include <iostream>


int main()
{
    // Allocate array memory
    // std::nothrow to ignore failled allocation exception
    int* array{ new (std::nothrow) int[]{0,2,3} };  

    if (array == nullptr) // If memory allocation fails
    {
        return -1; // Error early return
    }


    array[0] = 1;// to ignore unused variable

    /* Test compiler warning with wrong "delete array" instead of "delete[] array" */
    // delete array;
    /* Result: "error: 'void operator delete(void*, std::size_t)' called on pointer returned from a mismatched allocation function [-Werror=mismatched-new-delete]"*/

    // Correctly deallocate array memory 
    delete[] array;

    return 0;
}