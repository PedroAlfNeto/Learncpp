/*
 Quizz 1:
 a) Write a class named Fraction that has an integer numerator and denominator member.
 Write a print() function that prints out the fraction.

 The following main should compile:
*/

#include <iostream>

class Fraction
{
private:
    int m_num{};
    int m_den{1};

public:
    Fraction(int num, int den=1)
        : m_num{num}, m_den{den}
    {
    }

    void print()
    {
        std::cout << m_num << '/' << m_den << '\n';
    }
};

int main()
{
    Fraction f1{1, 4};
    f1.print();

    Fraction f2{1, 2};
    f2.print();

    return 0;
}