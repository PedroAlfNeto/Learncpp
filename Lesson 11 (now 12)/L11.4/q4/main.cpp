/*
 Quizz 4:
 Add two optimizations to the bubble sort algorithm you wrote in the previous quiz question:

 A) Notice how with each iteration of bubble sort, the biggest number remaining
    gets bubbled to the end of the array.
 After the first iteration, the last array element is sorted.
 After the second iteration, the second to last array element is sorted too.
 And so on… With each iteration, we don’t need to recheck elements that we know are already sorted.
 Change your loop to not re-check elements that are already sorted.

 B) If we go through an entire iteration without doing a swap, then we know the array
    must already be sorted.
 Implement a check to determine whether any swaps were made this iteration, and if not,
    terminate the loop early.
 If the loop was terminated early, print on which iteration the sort ended early.
*/

#include <iostream>
#include "main.hpp"

int main()
{
    // Array to be sorted
    int array1[]{6, 3, 2, 9, 7, 1, 5, 4, 8};

    // Determine lengh of array
    //int len{static_cast<int>(std::size(array1))}; // avoid magic number

    // Print unsorted array
    std::cout << "Printing unsorted array:\n";
    print_array(array1, std::size(array1));

    // Perform unoptimized bubblesort algorith
    bubblesort_unoptimized(array1, std::size(array1));

    // Print sorted array
    std::cout << "Printing array sorted with unoptimized bubblesort:\n";
    print_array(array1, std::size(array1));

    // Copy array for reusing unsorted array
    int array2[]{6, 3, 2, 9, 7, 1, 5, 4, 8};

    // Perform detection optimized bubblesort algorith
    bubblesort_optimized(array2, std::size(array2));

    std::cout << "Printing array sorted with detection optimized bubblesort:\n";
    print_array(array2, std::size(array2));

    return 0;
}

// Unoptimized bubblesort algorithm
void bubblesort_unoptimized(int array[], int length)
{
    int cnt{0};      // count bubblesort iterations
    int cnt_comp{0}; // count number comparisons by bubblesort

    // Perform a bubblesort cycle per each element (unoptimized)
    for (cnt = 0; cnt < length; cnt++)
    {
        // Compare sequential array elements and sort by increasing size
        for (int idx{0}; idx < length - 1; ++idx)
        {
            // Swap elements if sorting is needed
            if (array[idx] > array[idx + 1])
            {
                std::swap(array[idx], array[idx + 1]);
            }
            ++cnt_comp;
        }
    }
    std::cout << "Performed bubblesort iterations: " << cnt + 1 << " and " << cnt_comp << " comparisons\n";
}

// Optimized bubblesort algorithm
void bubblesort_optimized(int array[], int length)
{
    int cnt{0};      // count bubblesort iterations
    int cnt_comp{0}; // performance metric for comparison operations

    // Perform a bubblesort iteration per each element (unoptimized)
    for (cnt = 0; cnt < length; cnt++)
    {
        // For counting already optimized elements, reseting after each bubblesort iteration
        int cnt_swaped{0};

        // Compare sequential array elements and sort by increasing size 
        // The n-iteration already sorted the n-last element so no need for comparing > (length - 1 - cnt)
        for (int idx{0}; idx < (length - 1 - cnt) ; ++idx)
        {
            // Swap elements if sorting is needed
            if (array[idx] > array[idx + 1])
            {
                std::swap(array[idx], array[idx + 1]);
                ++cnt_swaped;
            }
            ++cnt_comp; // account for comparison operation
        }

        // For debugging bubblesort iterations
        //std::cout << "Step" << cnt+0 << ": ";
        //print_array(array, length);

        // Early detection that the array is already sorted
        if (cnt_swaped < 1)
        {
            break; // No need for further bubblesort cycles
        }
    }
    std::cout << "Performed bubble sort iterations: " << cnt + 1 << " and " << cnt_comp << " comparisons\n";
}

// Print array
void print_array(const int array[9], int length)
{
    std::cout << "array[9] = [ ";
    for (int i = 0; i < length - 1; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout << array[length - 1] << " ]\n\n";
}