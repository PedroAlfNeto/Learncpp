/*
 Quizz 1:
 b) Add overloaded multiplication operators to handle multiplication between
    a Fraction and integer, and between two Fractions.
    Use the friend function method.

Hint:
    To multiply two fractions, first multiply the two numerators together,
        and then multiply the two denominators together.
    To multiply a fraction and an integer, multiply the numerator of the fraction
        by the integer and leave the denominator alone.

 The following main should compile:
*/

#include <iostream>

class Fraction
{
private:
    int m_num{};
    int m_den{1};

public:
    Fraction(int num, int den = 1)
        : m_num{num}, m_den{den}
    {
    }

    void print()
    {
        std::cout << m_num << '/' << m_den << '\n';
    }

    friend Fraction operator*(const Fraction frac1, const Fraction frac2);

    friend Fraction operator*(const Fraction frac, int num);

    friend Fraction operator*(int num, const Fraction frac)
    {
        return frac * num;
    }
};

Fraction operator*(const Fraction frac1, const Fraction frac2)
{
    return {frac1.m_num * frac2.m_num, frac2.m_den * frac2.m_den};
}

Fraction operator*(const Fraction frac, int num)
{
    return {frac.m_num * num, frac.m_den};
}

int main()
{
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

    return 0;
}