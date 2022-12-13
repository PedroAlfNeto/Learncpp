/*
 Quizz 1:
 What type of conversion happens in each of the following cases? 
 Valid answers are: No conversion needed, numeric promotion, numeric conversion,
  won’t compile due to narrowing conversion. 
 Assume int and long are both 4 bytes.
*/

//#include "main.hpp"
#include <iostream>

int main()
{
    int a { 5 }; // 1a: No conversion needed
    int b { 'a' }; // 1b: numeric promotion -> char to int
    int c { 5.4 }; // 1c: won’t compile due to narrowing conversion (loss double to int)
    int d { true }; // 1d: numeric promotion -> bool to int
    int e { static_cast<int>(5.4) }; // 1e: No implicit* conversion needed -> conversion of double to int

    double f { 5.0f }; // 1f: numeric promotion -> float to double
    double g { 5 }; // 1g: numeric promotion -> int to double

    // Extra credit section
    long h { 5 }; // 1h: numeric promotion -> int to long

    float i { f }; // 1i: won’t compile due to narrowing conversion (loss double to float)
    float j { 5.0 }; // 1j:  corrected -> Numeric conversion of double to float (this is allowed since 5.0 is constexpr and fits in the range of the float)

    return 0;
}
