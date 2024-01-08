/*
 Quizz 1:
 Manually*** show how selection sort works on the following array:
    { 30, 60, 20, 50, 40, 10 }.
 Show the array after each swap that takes place.
*/

//#include "main.hpp"
#include <iostream>
#include <utility> // for using std::swap

int main()
{
    int array[]{30, 60, 20, 50, 40, 10};
    int array_len = static_cast<int>(std::size(array));

    // Hold smallest index in range
    int smallestIndex{};

    // loop each index for swaping in the n-smallest value
    for (int nIndex{0}; nIndex < array_len - 1; nIndex++)
    {
        // Assume n index is smallest
        smallestIndex=nIndex;
        
        // Identify smallest value index in range
        for (int i{nIndex}; i < array_len; i++)
        {
            if (array[i] < array[smallestIndex])
            {
                smallestIndex = i; // update smallest index with current smaller value in the range
            }
        }

        // Swap in n-smallest value to nIndex position
        std::swap(array[nIndex], array[smallestIndex]);

        // Print the array after swap.
        std::cout << "Sort step " << nIndex + 1 << ": [ ";
        for (int cnt{0}; cnt < array_len; cnt++)
        {
            if (cnt == nIndex || cnt == smallestIndex) // Highlight swapped values
            {
                std::cout << '*' << array[cnt] << '*';
            }
            else
            {
                std::cout << array[cnt];
            }

            if (cnt < array_len - 1)
                std::cout << ", ";
        }
        std::cout << " ]\n";

    }

    return 0;
}
