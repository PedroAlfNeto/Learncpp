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

 Now let’s handle the case where the fractional portion is out of bounds.
 We have two reasonable strategies here:

    Clamp the fraction portion (if >99, set to 99).
    Treat overflow as relevant (if >99, reduce by 100 and add 1 to base).

    In this exercise, we’ll treat decimal overflow as relevant, as this will be
    useful in the next step.

    The following should run:

    And produce the output:

    2.04
    2.04



*/

#include <cassert>
#include <iostream>

class FixedPoint2 {
   private:
    int m_base{};
    int m_fraction{};

   public:
    // Constructor
    FixedPoint2(int base, int frac) : m_base{base}, m_fraction{frac} {
        // If either (or both) of the non-fractional and fractional part of the
        // number are negative, the number should be treated as negative
        if (m_base < 0 || m_fraction < 0) {
            // std::cout << "DEBUG, before: base=" << m_base<< "; fraction= " << m_fraction << '\n';
            // Make sure base is negative
            if (m_base > 0) m_base = -m_base;
            // Make sure decimal is negative
            if (m_fraction > 0) m_fraction = -m_fraction;
        }


        // Treat overflow as relevant
        if (m_fraction>99 || m_fraction<-99){
            m_base+=m_fraction/100;
            m_fraction=m_fraction-(m_fraction/100)*100; //(discards lower data)
        }
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

// You will need to make testDecimal a friend of FixedPoint2
// so the function can access the private members of FixedPoint2
bool testDecimal(const FixedPoint2& fp) {
    if (fp.m_base >= 0)
        return fp.m_fraction >= 0 && fp.m_fraction < 100;
    else
        return fp.m_fraction <= 0 && fp.m_fraction > -100;
}

int main() {
    FixedPoint2 a{1, 104};
    std::cout << a << '\n';
    std::cout << static_cast<double>(a) << '\n';
    assert(static_cast<double>(a) == 2.04);
    assert(testDecimal(a));

    FixedPoint2 b{1, -104};
    assert(static_cast<double>(b) == -2.04);
    assert(testDecimal(b));

    FixedPoint2 c{-1, 104};
    assert(static_cast<double>(c) == -2.04);
    assert(testDecimal(c));

    FixedPoint2 d{-1, -104};
    assert(static_cast<double>(d) == -2.04);
    assert(testDecimal(d));

    return 0;
}