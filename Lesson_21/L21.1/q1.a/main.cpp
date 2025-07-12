/*
 Quizz 1:
 a) Write a class named Fraction that has an integer numerator and
 denominator member. Write a print() function that prints out the fraction.

 The main() code should compile and print:
    1/4
    1/2
*/

#include <iostream>

class Fraction {
   private:
    int m_numerator{};
    int m_denominator{1};

   public:
    explicit Fraction(int num, int den = 1)
        : m_numerator{num}, m_denominator{den} {}

    void print() const {
        std::cout << m_numerator << "/" << m_denominator << '\n';
    }
};

int main() {
    Fraction f1{1, 4};
    f1.print();

    Fraction f2{1, 2};
    f2.print();

    return 0;
}