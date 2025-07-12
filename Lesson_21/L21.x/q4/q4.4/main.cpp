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

 > Step #3

 Now add a constructor that takes a double. The follow main should run:

 Recommendation: This one will be a bit tricky. Do this one in three steps.
 First, solve for the cases where the double parameter is representable directly
 (variables a through c above).

 Then, update your code to handle the cases where the double parameter has a
 rounding error (variables d & e). Variables f and g should be handled by the
 overflow handling we added in the prior step.

*/

#include <cassert>
#include <iostream>

class FixedPoint2 {
   private:
    int m_base{};
    int m_fraction{};

   public:
    // Default Constructor with parameters
    FixedPoint2(int base, int frac) : m_base{base}, m_fraction{frac} {
        // If either (or both) of the non-fractional and fractional part of the
        // number are negative, the number should be treated as negative
        if (m_base < 0 || m_fraction < 0) {
            // Make sure base is negative
            if (m_base > 0) m_base = -m_base;
            // Make sure decimal is negative
            if (m_fraction > 0) m_fraction = -m_fraction;
        }

        // Treat overflow as relevant
        if (m_fraction > 99 || m_fraction < -99) {
            m_base += m_fraction / 100;
            m_fraction = m_fraction % 100;  // integer remainder
        }
    }

    // // Constructor with double parameter (reusing code)
    // FixedPoint2(double value)
    // : FixedPoint2(static_cast<int>(value)/1,
    // (value-static_cast<int>(value))*100)
    // {
    //     // int base=static_cast<int>(value);
    //     // int fraction=static_cast<int>(value)

    //     // FixedPoint2(base, fraction);
    //     std::cout << "Called constructor with double parameter" << '\n';
    //     // FixedPoint2(0, 1);
    // }

    // Constructor with double parameter (works for normal cases, but
    // duplication)
    FixedPoint2(double value) {
        // If either (or both) of the non-fractional and fractional part of the
        // number are negative, the number should be treated as negative
        m_base = static_cast<int>(value);
        // m_fraction = (value-m_base)*100;
        // m_fraction = (value-m_base)*100;
        m_fraction = (value * 100 - m_base * 100);

        // std::cout << "value=" << value << '\n';
        // std::cout << "value*100=" << value * 100 << '\n';
        // std::cout << "m_base=" << m_base << '\n';
        // std::cout << "(value-m_base)*100=" << (value - m_base) * 100 << '\n';
        // std::cout << "m_fraction=" << m_fraction << '\n';

        if (value < 0) {
            // Make sure base is negative
            if (m_base > 0) m_base = -m_base;
            // Make sure decimal is negative
            if (m_fraction > 0) m_fraction = -m_fraction;
        }

        // Treat overflow as relevant
        if (m_fraction > 99 || m_fraction < -99) {
            m_base += m_fraction / 100;
            m_fraction = m_fraction % 100;  // integer remainder
        }

        // std::cout << "value after=" << *this << '\n';

        // std::cout << "Called constructor with double parameter" << '\n';
    }

    explicit operator double() const {
        // ok to return rvalue
        double my_double{static_cast<double>(m_base) +
                         (static_cast<double>(m_fraction) / 100)};
        return my_double;
    }

    // osteam operator required
    friend std::ostream& operator<<(std::ostream& out, const FixedPoint2& num);

    friend bool testDecimal(const FixedPoint2& fp);
};

std::ostream& operator<<(std::ostream& out, const FixedPoint2& num) {
    out << static_cast<double>(num);
    return out;
}

int main() {
    FixedPoint2 a{0.01};
    std::cout << "a= " << a << "\n";
    assert(static_cast<double>(a) == 0.01);

    FixedPoint2 b{-0.01};
    assert(static_cast<double>(b) == -0.01);

    FixedPoint2 c{1.9};  // make sure we handle single digit decimal
    assert(static_cast<double>(c) == 1.9);

    FixedPoint2 d{5.01};  // stored as 5.0099999... so we'll need to round this
    assert(static_cast<double>(d) == 5.01);

    FixedPoint2 e{
        -5.01};  // stored as -5.0099999... so we'll need to round this
    assert(static_cast<double>(e) == -5.01);

    // Handle case where the argument's decimal rounds to 100 (need to increase
    // base by 1)
    FixedPoint2 f{106.9978};  // should be stored with base 107 and decimal 0
    std::cout << "f= " << f << "\n";
    assert(static_cast<double>(f) == 107.0);

    // Handle case where the argument's decimal rounds to -100 (need to decrease
    // base by 1)
    FixedPoint2 g{-106.9978};  // should be stored with base -107 and decimal 0
    assert(static_cast<double>(g) == -107.0);

    return 0;
}