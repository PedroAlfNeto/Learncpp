/*
 Quizz 1:
 e) Extra credit: the fraction 2/4 is the same as 1/2, but 2/4 is not reduced to the lowest terms. 
 We can reduce any given fraction to lowest terms by finding the greatest common divisor (GCD) 
    between the numerator and denominator, and then 
    dividing both the numerator and denominator by the GCD.

std::gcd was added to the standard library in C++17 (in the <numeric> header).

 The following main should compile:
*/

#include <iostream>
#include <numeric> // for std::gcd -> greatest common divisor

class Fraction
{
private:
    int m_num{};
    int m_den{1};

    void reduce()
    {
        int greatest_common_divisor{std::gcd(m_num,m_den)};
        if (greatest_common_divisor) // Make sure we don't try to divide by 0
		{
        m_num/=greatest_common_divisor;
        m_den/=greatest_common_divisor;
        }
    }


public:
    Fraction(int num, int den = 1)
        : m_num{num}, m_den{den}
    {
        reduce();
    }

    void print()
    {
        // reduce(); // reduce can also be in print ;) save effort
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

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4} };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}