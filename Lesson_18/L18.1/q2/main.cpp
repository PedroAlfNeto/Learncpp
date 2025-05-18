/*
 Quizz 2:
 Rewrite the selection sort code above to sort in descending order (largest numbers first). 
 Although this may seem complex, it is actually surprisingly simple.
*/

//#include "main.hpp"
#include <iostream>
#include <utility> // for using std::swap

int main()
{
    int array[]{30, 60, 20, 50, 40, 10};
    int array_len = static_cast<int>(std::size(array));

    // loop each index for swaping in the n-max value
    for (int nIndex{0}; nIndex < array_len - 1; nIndex++)
    {
        // Hold max index in range
        int maxIndex{nIndex}; // assume nIndex is max

        // Identify max value index in range
        for (int i{nIndex}; i < array_len; i++)
        {
            if (array[i] > array[maxIndex])
            {
                maxIndex = i; // update max index with current max value in the range
            }
        }

        // Swap in n-smallest value to nIndex position
        std::swap(array[nIndex], array[maxIndex]);

        // Print the array after swap.
        std::cout << "Sort step " << nIndex << ": [ ";
        for (int cnt{0}; cnt < array_len; cnt++)
        {
            if (cnt == nIndex || cnt == maxIndex) // Highlight swapped values
            {
                std::cout << "*" << array[cnt] << '*';
            }
            else
            {
                std::cout << array[cnt];
            }
            if(cnt<array_len-1) std::cout <<", ";
        }
        std::cout << " ]\n";

    }

    return 0;
}
