/*
 Quizz 1:
     Add the six comparison operators to the Fraction class so that the
 following program compiles:

*/
#include <iostream>
#include <numeric>  // for std::gcd

class Fraction {
   private:
    int m_num{};
    int m_den{};

   public:
    Fraction(int numerator = 0, int denominator = 1)
        : m_num{numerator}, m_den{denominator} {
        // We put reduce() in the constructor to ensure any new fractions we
        // make get reduced! Any fractions that are overwritten will need to be
        // re-reduced
        reduce();
    }

    void reduce() {
        int gcd{std::gcd(m_num, m_den)};
        if (gcd) {
            m_num /= gcd;
            m_den /= gcd;
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1);

    friend bool operator==(const Fraction& f1, const Fraction& f2);
    friend bool operator!=(const Fraction& f1, const Fraction& f2);
    friend bool operator<(const Fraction& f1, const Fraction& f2);
    friend bool operator>(const Fraction& f1, const Fraction& f2);
    friend bool operator<=(const Fraction& f1, const Fraction& f2);

};

std::ostream& operator<<(std::ostream& out, const Fraction& f1) {
    out << f1.m_num << '/' << f1.m_den;
    return out;
}

bool operator==(const Fraction& f1, const Fraction& f2) {
    // relies on always reduced format enforced by constructor
    return ((f1.m_num==f2.m_num) && (f1.m_den==f2.m_den));
}
bool operator!=(const Fraction& f1, const Fraction& f2) {
    return (!operator==(f1,f2));
}

bool operator<(const Fraction& f1, const Fraction& f2) {
    double val1{static_cast<double>(f1.m_num) / f1.m_den};
    double val2{static_cast<double>(f2.m_num) / f2.m_den};
    return (val1 < val2);
}

bool operator>(const Fraction& f1, const Fraction& f2) {
    //  bigger (>) if not equal (==) and not less (<)
    return (!(operator==(f1,f2)) && !(operator<(f1,f2)));
}

bool operator>=(const Fraction& f1, const Fraction& f2) {
    //  bigger or equal (>=) if not less (<)
    return (!(operator<(f1,f2)));
}

bool operator<=(const Fraction& f1, const Fraction& f2) {
    //  less or equal (>=) if not bigger (>)
    return (!(operator>(f1,f2)));
}

int main() {
    Fraction f1{3, 2};
    Fraction f2{5, 8};

    std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
    std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
    std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
    std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
    std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
    std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
    return 0;
}