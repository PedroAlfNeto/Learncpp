/*
 Quizz 1:
 e) Extra credit: the fraction 2/4 is the same as 1/2, but 2/4 is not reduced to
the lowest terms. We can reduce any given fraction to lowest terms by finding
the greatest common divisor (GCD) between the numerator and denominator, and
then dividing both the numerator and denominator by the GCD.

std::gcd() was added to the standard library in C++17 (in the <numeric> header).

Write a member function named reduce() that reduces your fraction. Make sure all
fractions are properly reduced.

*/

#include <iostream>
#include <numeric>  // for std::gcd

class Fraction {
   private:
    int m_num{};
    int m_den{1};

    // Reduce fraction to common denominator.Mutator method
    void reduce() {
        int gcd{std::gcd(m_num, m_den)};

        if (gcd != 0)  // Make sure we don't try to divide by 0
        {
            m_num /= gcd;
            m_den /= gcd;
        }
    }

   public:
    Fraction(int num, int den = 1) : m_num{num}, m_den{den} {
        // always reduce new fractions
        this->reduce();
    }

    void print() const { std::cout << m_num << "/" << m_den << '\n'; }

    friend Fraction const operator*(const Fraction& f1, const Fraction& f2) {
        int calcNum{f1.m_num * f2.m_num};
        int calcDen{f1.m_den * f2.m_den};

        return {calcNum, calcDen};
    }

    friend Fraction operator*(const Fraction& f1, int f2) {
        return Fraction{f1 * Fraction{f2, 1}};  // reuse existing operator
    }

    friend Fraction operator*(int f1, const Fraction& f2) {
        return Fraction{Fraction{f1, 1} * f2};  // reuse existing operator
    }
};

int main() {
    Fraction f1{2, 5};
    f1.print();

    Fraction f2{3, 8};
    f2.print();

    Fraction f3{f1 * f2};
    f3.print();

    Fraction f4{f1 * 2};
    f4.print();

    Fraction f5{2 * f2};
    f5.print();

    Fraction f6{Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4}};
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}