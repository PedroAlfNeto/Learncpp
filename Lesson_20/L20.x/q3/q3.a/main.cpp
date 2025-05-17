/*
 Quizz 3:
 The best algorithm for determining whether a value exists in a sorted array is
 called binary search.

 Binary search works as follows:
 - Look at the center element of the array (if the array has an even number of
 elements, round down).
 - If the center element is greater than the target element, discard the top
 half of the array (or recurse on the bottom half).
 - If the center element is less than the target element, discard the bottom
 half of the array (or recurse on the top half).
 - If the center element equals the target element, return the index of the
 center element.
 - If you discard the entire array without finding the target element, return a
 sentinel that represents “not found” (in this case, we’ll use -1, since it’s an
 invalid array index).

 Because we can throw out half of the array with each iteration, this algorithm
 is very fast.
 Even with an array of a million elements, it only takes at most
 20 iterations to determine whether a value exists in the array or not! However,
 it only works on sorted arrays.

 Modifying an array (e.g. discarding half the elements in an array) is
 expensive, so typically we do not modify the array. Instead, we use two
 integers (min and max) to hold the indices of the minimum and maximum elements
 of the array that we’re interested in examining.

 Let’s look at a sample of how this algorithm works, given an array { 3, 6, 7,
 9, 12, 15, 18, 21, 24 }, and a target value of 7. At first, min = 0, max = 8,
 because we’re searching the whole array (the array is length 9, so the index of
 the last element is 8).

-  Pass 1) We calculate the midpoint of min (0) and max (8), which is 4.
 Element #4 has value 12, which is larger than our target value.
 Because the array is sorted, we know that all elements with index equal to or
 greater than the midpoint (4) must be too large. So we leave min alone, and set
 max to 3.
- Pass 2) We calculate the midpoint of min (0) and max (3), which is 1.
 Element #1 has value 6, which is smaller than our target value. Because the
 array is sorted, we know that all elements with index equal to or lesser than
 the midpoint (1) must be too small. So we set min to 2, and leave max alone.
- Pass 3) We calculate the midpoint of min (2) and max (3), which is 2.
 Element #2 has value 7, which is our target value. So we return 2.

 In C++20, calculating the midpoint can be done via calling std::midpoint.
 Prior to C++20, you’ll need to calculate the midpoint yourself --
 in this case you can use min + ((max - min) / 2) to avoid overflow
 (when min and max are both positive).

 Given the following code:
 a) Write an iterative version of the binarySearch function.
 Hint: You can safely say the target element doesn’t exist when the min index is
greater than the max index.
*/

#include <iostream>
#include <iterator>
#include <numeric>  // for std::midpoint

namespace config {
constexpr bool kUseCpp20{true};
constexpr bool kDebugMode{false};
}  // namespace config

int calcMidpoint(int min, int max) {
    int mid{};
    if (config::kUseCpp20) {
        // approach with C++20
        mid = std::midpoint(min, max);
    } else {
        // own approach
        mid = min + ((max - min) / 2);
    }

    if (config::kDebugMode) {
        std::cout << "Midpoint of (" << min << "," << max << ") = " << mid
                  << "\n";
    }

    return mid;
}

// array is the array to search over.
// target is the value we're trying to determine exists or not.
// min is the index of the lower bounds of the array we're searching.
// max is the index of the upper bounds of the array we're searching.
// binarySearch() should return the index of the target element if the target is
// found, -1 otherwise
int binarySearch(const int* array, int target, int min, int max) {
    // iteractive bisect until discarding entire array
    // when min > max bisecting is done without finding target
    while (min <= max) {
        // determine midpoint
        int midpoint{calcMidpoint(min, max)};

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
            return midpoint;
        }
    }
    // target doesn’t exist when min is greater than max.

    return -1;  // did not find target
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