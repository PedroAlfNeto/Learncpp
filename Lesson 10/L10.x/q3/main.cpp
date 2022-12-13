/*
 Create a class template named Triad that has 3 members of the same template type.
 The following program should compile and produce the result:
    [1, 2, 3][1.2, 3.4, 5.6]

If you are using C++17, you will need to provide a deduction guide for CTAD to work.
*/

#include "main.hpp"
#include <iostream>
#include <string>      // For std::string usage
#include <cassert>     // For assert usage
#include <string_view> // C++17

template <typename U>
struct Triad
{
    U a;
    U b;
    U c;
};

template <typename U>
void print(const Triad<U>& t)
{
    // Must print [1, 2, 3][1.2, 3.4, 5.6]
    std::cout << '[' << t.a << ", " << t.b << ", " << t.c << ']';
}

int main()
{
    Triad t1{1, 2, 3}; // note: uses CTAD to deduce template arguments
    print(t1);

    Triad t2{1.2, 3.4, 5.6}; // note: uses CTAD to deduce template arguments
    print(t2);

    return 0;
}

