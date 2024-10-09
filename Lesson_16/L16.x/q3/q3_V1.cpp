/*
 Question #3 (my version)

 Write a function that takes a std::vector, returns a std::pair containing the
 indices of the elements with the min and max values in the array.
 The documentation for std::pair can be found here.

 Call the function on the following two vectors:
    std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
    std::vector v2 { 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 };

 The program should output the following:

    With array ( 3, 8, 2, 5, 7, 8, 3 ):
    The min element has index 2 and value 2
    The max element has index 1 and value 8

    With array ( 5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6 ):
    The min element has index 4 and value 1.2
    The max element has index 5 and value 8.8

*/

#include <cassert>
#include <iostream>
#include <string_view>
#include <utility>  // for std::pair
#include <vector>

// print array
template <typename T>
void printArray(const std::vector<T> &vec) {
    bool skip_comma{true}; //  prevent extra comma printed
    std::cout << "With array ( ";
    for (const auto &value : vec) {
        if (skip_comma) {
            skip_comma = false;
        } else {
            std::cout << ", ";
        }
        std::cout << value ;
    }
    std::cout << " ):\n";
}

// get array maximum index and value
template <typename T>
std::pair<ssize_t, T> getVecMax(const std::vector<T> &vec) {
    // Initalize max val to first index to support negative numbers
    ssize_t maxIdx{};
    T maxVal{vec.at(maxIdx)};

    // Loop through array to get max idx and value
    // cant use range-based for loop
    for (ssize_t idx{}; idx < static_cast<ssize_t>(std::size(vec)); ++idx) {
        T curr_val{vec.at(idx)};  // single access
        // only first max will get captured
        if (curr_val > maxVal) {
            // update max values
            maxIdx = idx;
            maxVal = curr_val;
        }
    }

    return {maxIdx, maxVal};
}

// get array minimum index and value
template <typename T>
std::pair<ssize_t, T> getVecMin(const std::vector<T> &vec) {
    // Initalize min val to first index to support negative numbers
    ssize_t minIdx{};
    T minVal{vec.at(minIdx)};

    // Loop through array to get min idx and value
    // cant use range-based for loop
    for (ssize_t idx{}; idx < static_cast<ssize_t>(std::size(vec)); ++idx) {
        T curr_val{vec.at(idx)};  // single access
        // only first min will get captured
        if (curr_val < minVal) {
            // update min values
            minIdx = idx;
            minVal = curr_val;
        }
    }

    return {minIdx, minVal};
}

template <typename T>
void printAbsolutes(const std::vector<T> &vec) {
    std::pair vec_min{getVecMin(vec)};
    std::pair vec_max{getVecMax(vec)};
    printArray(vec);
    std::cout << "The min element has index " << vec_min.first << " and value "
              << vec_min.second << '\n';
    std::cout << "The max element has index " << vec_max.first << " and value "
              << vec_max.second << "\n\n";
}

int main() {
    std::vector v1{3, 8, 2, 5, 7, 8, 3};
    std::vector v2{5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6};

    printAbsolutes(v1);
    printAbsolutes(v2);

    return 0;
}