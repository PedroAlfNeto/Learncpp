/*
 Quizz 3: (v1 my original version)
 b) Write a recursive version of the binarySearch function.
*/

#include <iostream>
#include <iterator>
#include <numeric>  // for std::midpoint

namespace config {
constexpr bool kDebugMode{false};
}  // namespace config

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is
// found, -1 otherwise
int binarySearch(const int* array, int target, int min, int max) {   
    if (min <= max){
        // determine midpoint
        int midpoint{std::midpoint(min, max)};

        int value{array[midpoint]};
        if (config::kDebugMode) {
            std::cout << "Value is: " << value << "\n";
        }

        if (value < target) {
            // discard bottom half (including midpoint element already checked)
            min = midpoint + 1;
        } else if (value > target) {
            // discard top half (including midpoint element already checked)
            max = midpoint - 1;
        } else {  // value == target
            return midpoint; // target found
        }

        // search in adjusted array
        return binarySearch(array, target, min, max); // recusion point
    } else{
        // if we get here, we didn't find the target
        if (config::kDebugMode) {
            std::cout << "Target not found\n";
        }

        // termination condition
        return -1;  // did not find target 
        // will undwind to return -1 to original caller
    }
}

int main() {
    constexpr int array[]{3,  6,  8,  12, 14, 17, 20, 21,
                          26, 32, 36, 37, 42, 44, 48};
    constexpr int arrSize{std::size(array)};

    // We're going to test a bunch of values to see if the algorithm returns the
    // result we expect

    // Here are the test values
    constexpr int testValues[]{0, 3, 12, 13, 22, 26, 43, 44, 48, 49};

    // And here are the results that we expect for those test values
    int expectedResult[]{-1, 0, 3, -1, -1, 8, -1, 13, 14, -1};

    // Make sure we have the same number of test values and expected results
    static_assert(std::size(testValues) == std::size(expectedResult));

    int numTestValues{std::size(testValues)};
    // Loop through all of the test values
    for (int count{0}; count < numTestValues; ++count) {
        if (config::kDebugMode) {
            std::cout << "\n\nTesting " << testValues[count] << "\n";
        }
        // See if our test value is in the array
        int index{binarySearch(array, testValues[count], 0, arrSize - 1)};
        // If it matches our expected value, then great!
        if (index == expectedResult[count])
            std::cout << "test value " << testValues[count] << " passed!\n";
        else  // otherwise, our binarySearch() function must be broken
            std::cout << "test value " << testValues[count]
                      << " failed. Returned index=" << index
                      << ". There's something wrong with your code!\n";
    }

    return 0;
}