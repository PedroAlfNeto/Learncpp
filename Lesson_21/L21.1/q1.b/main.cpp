/*
 Quizz 1:
 b) Add overloaded multiplication operators to handle multiplication between a
 Fraction and integer, and between two Fractions. Use the friend function
 method.

 The main() code should compile and print:

    2/5
    3/8
    6/40
    4/5
    6/8
    6/24
*/

#include <iostream>

class Fraction {
   private:
    int m_num{};
    int m_den{1};

   public:
   explicit Fraction(int num, int den=1) : m_num{num}, m_den{den} {}

    void print() const {
        std::cout << m_num << "/" << m_den << '\n';
    }

    friend Fraction const operator*(const Fraction& f1,const Fraction& f2){
        int calcNum{f1.m_num*f2.m_num};
        int calcDen{f1.m_den*f2.m_den};

        return Fraction{calcNum,calcDen};
    }

    friend Fraction operator*(const Fraction& f1, int f2){
        return Fraction{f1.m_num*f2,f1.m_den};
        // return  Fraction{f1*Fraction{f2,1}}; // reuse existing operator
    }

    friend Fraction operator*(int f1,const Fraction& f2){
        return Fraction{f1*f2.m_num,f2.m_den};
        // return  Fraction{Fraction{f1,1}*f2}; // reuse existing operator
    }
};

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

    return 0;
}