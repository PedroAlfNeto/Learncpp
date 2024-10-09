/*
 Quizz 1:
 Write definitions for the following. Use CTAD where possible (13.14 -- Class
 template argument deduction (CTAD) and deduction guides).

*/

#include <vector>
#include <string_view>

int main() {
    // a) A std::vector initialized with the first 6 even numbers.

    std::vector vec_a{2, 4, 6, 8, 10, 12};  // before C++17: vector<int>

    // b) A constant std::vector initialized with the values 1.2, 3.4, 5.6,
    // and 7.8.

    const std::vector vec_b {
        1.2, 3.4, 5.6, 7.8
    }  // before C++17: vector<double>

    // c) A constant std::vector of std::string_view initialized with the names
    // “Alex”, “Brad”, “Charles”, and “Dave”.
    const std::vector<std::string_view> vec_c {
        "Alex", "Brad", "Charles", "Dave"
    }

    // d) A std::vector with the single element value 12.
    std::vector v_d { 12 };

    // e) A std::vector with 12 int elements, initialized to the default values.
    std::vector<int> v_e (12);

    return 0;
}
