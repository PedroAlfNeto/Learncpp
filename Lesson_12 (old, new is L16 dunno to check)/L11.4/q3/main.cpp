/*
 Quizz 3:
 Unoptimized bubble sort performs the following steps to sort an array from smallest to largest:
    A) Compare array element 0 with array element 1. If element 0 is larger, swap it with element 1.
    B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you hit the end of the array. At this point, the last element in the array will be sorted.
    C) Repeat the first two steps again until the array is sorted.

    Write code that bubble sorts the array according to the rules above

    Print the sorted array elements at the end of your program.
*/

#include <iostream>
#include <utility>
#include <chrono> // for timing the sort algorithms

void print_array(const int array[9], int length);
void bubblesort_unoptimized(int array[9], int length);
void bubblesort_optimized_detection(int array[9], int lenght);

int main()
{
    // Original array to be sorted
    int array1[]{6, 3, 2, 9, 7, 1, 5, 4, 8};

    // Determine lengh of array
    int len{static_cast<int>(std::size(array1))}; // avoid magic number

    // Print unsorted array
    std::cout << "Printing unsorted array:\n";
    print_array(array1, len);

    // Perform unoptimized bubblesort algorith
    bubblesort_unoptimized(array1, len);

    // Print sorted array
    std::cout << "Printing array sorted with unoptimized bubblesort:\n";
    print_array(array1, len);

    // Copy array for reusing unsorted array
    int array2[]{6, 3, 2, 9, 7, 1, 5, 4, 8};

    // Print unsorted array
    //std::cout << "Printing unsorted array:\n";
    //print_array(array2, len);

    // Perform detection optimized bubblesort algorith
    bubblesort_optimized_detection(array2, len);

    std::cout << "Printing array sorted with detection optimized bubblesort:\n";
    print_array(array2, len);

    return 0;
}

// Unoptimized bubblesort algorithm
void bubblesort_unoptimized(int array[], int length)
{
    int cnt{0};
    // Perform a bubblesort cycle per each element (unoptimized)
    for (cnt=0; cnt < length; cnt++)
    {
        // Compare sequential array elements and sort by increasing size
        for (int idx{0}; idx < length - 1; ++idx)
        {
            // Swap elements if sorting is needed
            if (array[idx] > array[idx + 1])
                std::swap(array[idx], array[idx + 1]);
        }
    }
    std::cout << "Performed bubble sort iterations: " << cnt+1 << '\n';
}

// Optimized bubblesort algorithm (by Pedro)
void bubblesort_optimized_detection(int array[], int lenght)
{

    int cnt{0};
    // Perform a bubblesort iteration per each element (unoptimized)
    for (cnt=0; cnt < lenght; cnt++)
    {
        // For counting already optimized elements, reseting after each bubblesort iteration
        int cnt_sorted{0};

        // Compare sequential array elements and sort by increasing size
        for (int idx{0}; idx < lenght - 1; ++idx)
        {
            // Swap elements if sorting is needed
            if (array[idx] > array[idx + 1])
                std::swap(array[idx], array[idx + 1]);
            else
                cnt_sorted++;
        }
        // Early detection that the array is already sorted
        if (cnt_sorted == lenght - 1){
            break; // No need for further bubblesort cycles
        }
    }
    std::cout << "Performed bubble sort iterations: " << cnt+1 << '\n';
}

// Print array
void print_array(const int array[9], int lenght)
{
    std::cout << "array[9] = [ ";
    for (int i = 0; i < lenght - 1; i++)
    {
        std::cout << array[i] << ", ";
    }
    std::cout << array[lenght - 1] << " ]\n\n";
}