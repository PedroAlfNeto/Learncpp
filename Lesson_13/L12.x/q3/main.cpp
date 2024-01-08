/*
 Quizz 3:
 The best algorithm for determining whether a value exists in a sorted array is called binary search.

 a) Write an iterative version of the binarySearch function.
 Hint: You can safely say the target element doesn’t exist when 
 the min index is greater than the max index.


*/

#include <iostream>
#include <iterator>
#include <algorithm>
#include <cassert>

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch_iterative(const int* array, int target, int min, int max)
{   
    // auxiliary index variable to look through array
    int idx{};

    // breaks 
    while (min <= max)
    {
        // Set index to the center of the range
        idx = (max+min)/2;

        // If element found, return successfuly the value
        if(array[idx]==target) return idx;

        // If center element is larger than target, adjust range to lower half 
        else if(array[idx]>target){
            max=idx-1;
        }

        // If center element is smaller than target, adjust range to higher half 
        else{
            min=idx+1;
        }
    }

    // fail return condition
    return -1;
}

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is found, -1 otherwise
int binarySearch_recursive(const int* array, int target, int min, int max)
{   
    // auxiliary index variable to look through array
    static int idx{};   // static to preserve values between recursive returns

    // returns not found idicator if target is not present in range
    // if(std::binary_search(array[min],array[max],target)) //Don’t use these functions to solve the quiz, but use them in the future if you need a binary search.
    //     return -1;
    
    // Recursion break condition
    if (min <= max)
    {
        // Set index to the center of the range
        idx = (max+min)/2;

        // If element found, return successfuly the value
        if(array[idx]==target) return idx;

        // If center element is larger than target, adjust range to lower half 
        else if(array[idx]>target){
            max=idx-1;
        }

        // If center element is smaller than target, adjust range to higher half 
        else{
            min=idx+1;
        }

        // Recusively call funtion with update range
        if(binarySearch_recursive(array, target, min, max) >=0)
        {
            // For recursive exits returning index if found 
            return idx;
        }

    }

    // fail return condition
    return -1;
}

int main()
{
    constexpr int array[]{ 3, 6, 8, 12, 14, 17, 20, 21, 26, 32, 36, 37, 42, 44, 48 };

    // We're going to test a bunch of values to see if they produce the expected results
    constexpr int numTestValues{ 9 };
    // Here are the test values
    constexpr int testValues[numTestValues]{ 0, 3, 12, 13, 22, 26, 43, 44, 49 };
    // And here are the expected results for each value
    int expectedValues[numTestValues]{ -1, 0, 3, -1, -1, 8, -1, 13, -1 };

    // Loop through all of the test values
    for (int count{ 0 }; count < numTestValues; ++count)
    {
        // See if our test value is in the array (iterative version)
        // int index{ binarySearch_iterative(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        // See if our test value is in the array (recursive version)
        int index{ binarySearch_recursive(array, testValues[count], 0, static_cast<int>(std::size(array)) - 1) };
        
        // If it matches our expected value, then great!
        if (index == expectedValues[count])
             std::cout << "test value " << testValues[count] << " passed!\n";
        else // otherwise, our binarySearch() function must be broken
             std::cout << "test value " << testValues[count] << " failed.  There's something wrong with your code!\n";
    }

    return 0;
}