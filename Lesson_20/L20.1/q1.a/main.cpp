/*
 Quizz 1:

 1 - In this quiz, we’re going to write a version of our basic calculator using
 function pointers.

 1a) Create a short program asking the user for two integer inputs and a
 mathematical operation (‘+’, ‘-‘, ‘*’, ‘/’). Ensure the user enters a valid
 operation.
*/

#include <iostream>

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
