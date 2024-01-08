/*
 Quizz 2:
    Convert Fraction from a struct to a class following the standard best
 practices. Convert all of the functions to member functions.

 Question #3
    In the prior quiz solution, why was the Fraction constructor made explicit?
    
    A: Prevent incorrect usage of constructure to instanciate incorrect object, 
    given the constructor supports a single argument (defaul second parameter).
    Best practice

 Question #4
    Extra credit: In the Fraction quiz question, which of the member functions
    are probably better left as non-member functions, and why?
 
    A:         
*/

#include <iostream>

class Fraction {
 private:
  int m_num{};
  int m_den{};  // class invariant, denominator should never be 0
 public:
  // default constructor
  Fraction(int num = 0, int den = 1) {
    m_num = num;
    // invariant protection
    while (den == 0) {
      std::cout << "Enter a value for denominator: ";
      std::cin >> den;
      std::cout << '\n';

      if (den == 0) std::cout << "denominator cant be 0, insert another: ";
    }

    m_den = den;
  }

  void getFraction() {
    std::cout << "Enter a value for numerator: ";
    std::cin >> m_num;
    std::cout << '\n';

    std::cout << "Enter a value for denominator: ";
    std::cin >> m_den;
    std::cout << '\n';

    // invariant protection
    while (m_den == 0) {
      std::cout << "denominator cant be 0, insert another: ";
      std::cin >> m_den;
      std::cout << '\n';
    }
  }

  Fraction multiply(const Fraction& f2) const {
    return {m_num * f2.m_num, m_den * f2.m_den};
  }  // return temporary Fraction object using copy constructor

  void printFraction() const {
    std::cout << m_num << '/' << m_den << '\n';
  }  // use temporary Fraction object to print values
};

int main() {
  Fraction f1{};
  f1.getFraction();

  Fraction f2{};
  f2.getFraction();

  std::cout << "Your fractions multiplied together: ";

  f1.multiply(f2).printFraction();

  return 0;
}
