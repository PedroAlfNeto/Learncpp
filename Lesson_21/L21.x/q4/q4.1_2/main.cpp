/*
 Quizz 4:

 Extra credit: This one is a little more tricky.

 A floating point number is a number with a decimal where the number of digits
  after the decimal can be variable.
 A fixed point number is a number with a fractional component where the number
 of digits in the fractional portion is fixed.

 In this quiz, we’re going to write a class to implement a fixed point number
  with two fractional digits (e.g. 12.34, 3.00, or 1278.99).

 Assume that the range of the class should be -32768.99 to 32767.99, that the
  fractional component should hold any two digits, that we don’t want precision
  errors, and that we want to conserve space.

 > Step #1

 What type of member variable(s) do you think we should use to implement our
  fixed point number with 2 digits after the decimal? (Make sure you read the
  answer before proceeding with the next questions)
 A: int for integer and fractional part (16bit not enough for signed int (2^15
 -1=32767) by 1
 For fractional 8bit would more than suffice but better let compiler optimize.

 > Step #2

 Write a class named FixedPoint2 that implements the recommended solution from
 the previous question. If either (or both) of the non-fractional and fractional
 part of the number are negative, the number should be treated as negative.
 Provide the overloaded operators and constructors required for the following
 program to run. For now, don’t worry about the fractional portion being out of
 bounds (>99 or <-99).

 This program should produce the result:

    34.56
    34.56


*/

#include <cassert>
#include <iostream>

class FixedPoint2 {
   private:
    int m_base{};
    int m_fraction{};

   public:
    // Constructor
    FixedPoint2(int base, int frac) : m_base{base}, m_fraction{frac} {}

    explicit operator double() const {
        // ok to return rvalue
        double my_double{static_cast<double>(std::abs(m_base)) +
                         (static_cast<double>(std::abs(m_fraction)) / 100)};
        // If either non-fractional and fractional part of the number are
        // negative, the number should be treated as negative.
        if ((m_base < 0) || (m_fraction < 0)) my_double = -my_double;
        return my_double;
    }

    // osteam operator required
    friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& num);
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& num) {
    out << static_cast<double>(num);
    return out;
}

int main() {
    FixedPoint2 a{34, 56};
    std::cout << a << '\n';
    std::cout << static_cast<double>(a) << '\n';
    assert(static_cast<double>(a) == 34.56);

    FixedPoint2 b{-2, 8};
    assert(static_cast<double>(b) == -2.08);

    FixedPoint2 c{2, -8};
    assert(static_cast<double>(c) == -2.08);

    FixedPoint2 d{-2, -8};
    assert(static_cast<double>(d) == -2.08);

    FixedPoint2 e{0, -5};
    assert(static_cast<double>(e) == -0.05);

    FixedPoint2 f{0, 10};
    assert(static_cast<double>(f) == 0.1);

    return 0;
}