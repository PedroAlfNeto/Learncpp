/*
 Quizz 1:
 Create a struct to hold a fraction. The struct should have an integer numerator and an integer denominator member.

 Write a function to read in a Fraction from the user, and use it to read-in two fraction objects.
 Write another function to multiply two Fractions together and return the result as a Fraction (you don’t need to reduce the fraction).
 Write another function that prints a fraction.

 When multiplying two fractions together, the resulting numerator is the product of the two numerators,
 and the resulting denominator is the product of the two denominators.
*/

//#include "main.hpp"
#include <iostream>

struct Fraction
{
    int num{}; // numerator
    int den{}; // denominator
};

// Write a function to read in a Fraction from the user, and use it to read-in two fraction objects.
Fraction readFrac()
{
    Fraction frac{};
    std::cout << "Enter a value for the numerator: ";
    std::cin >> frac.num;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> frac.den;

    return frac;
}

// Write another function to multiply two Fractions together and return the result as a Fraction
Fraction multFracs(const Fraction& frac1,const Fraction& frac2)
{
    // Multiply fractions
    Fraction fracRes{(frac1.num * frac2.num), frac1.den * frac2.den};

    return fracRes;
}

main()
{
    Fraction fraction1{readFrac()};
    Fraction fraction2{readFrac()};

    Fraction result{multFracs(fraction1, fraction2)};

    std::cout << "Your fractions multiplied together: " << result.num << '/' << result.den << '\n';

    return 0;
} // All correct :)