/*
 Quizz 1:
 Write a function called calculate() that takes two integers and a char representing one of the
 following mathematical operations: +, -, *, /, or % (modulus).
 Use a switch statement to perform the appropriate mathematical operation on the integers, and
 return the result.
 If an invalid operator is passed into the function, the function should print an error.
 For the division operator, do an integer division.
*/

#include "main.hpp" // Revise header files
#include <iostream>

int main()
{
    // Request first integer
    int a{getInteger()};

    // Request opertion
    char oper{getoper()};

    // Request second integer
    int b{getInteger()};

    // Perform calculation
    calculator(a, b, oper);

    return 0;
}

int getInteger()
{
    std::cout << "\nEnter an integer: ";
    int val{};
    std::cin >> val;

    return val;
}

char getoper()
{
    std::cout << "\nEnter one of the following operators: +, -, *, /, or %: ";
    char op{};
    std::cin >> op;

    return op;
}

void calculator(int n1, int n2, char oper)
{

    int res{};

    switch (oper)
    {
    case '+':
        res = n1 + n2;
        break;
    case '-':
        res = n1 - n2;
        break;
    case '*':
        res = n1 * n2;
        break;
    case '/':
        res = n1 / n2;
        break;
    case '%':
        res = n1 % n2;
        break;
    default:
        std::cout << "Error Invalid operator inserted!\n";
        return;
    }

    // Print results
    std::cout << '\n'
              << n1 << oper << n2 << " = " << res << '\n';

    return;
}
