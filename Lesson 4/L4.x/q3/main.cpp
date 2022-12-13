/*
Quizz 3:
 Write the following program: The user is asked to enter 2 floating point numbers (use doubles).
 The user is then asked to enter one of the following mathematical symbols: +, -, *, or /.
 The program computes the answer on the two numbers the user entered and prints the results.
 If the user enters an invalid symbol, the program should print nothing.
*/

#include <iostream>

double getUserValue();

char getUserOperator();

double calculator(double val1, double val2, char operr);

int main()
{

    // Get two user values
    double alg1{}, alg2{};
    alg1 = getUserValue();
    alg2 = getUserValue();

    // Get operator from user
    char oper{};
    oper = getUserOperator();
    if (oper != '*' && oper != '/' && oper != '+' && oper != '-') // validate operator
        return -1;                                                // return main with error

    // Calculate value
    double res{};
    res = calculator(alg1, alg2, oper);

    // Print result
    std::cout << alg1 << ' ' << oper << ' ' << alg2 << " = " << res << "\n";

    return 0;
}

// Request double value from user
double getUserValue()
{

    double val{};
    std::cout << "Enter a double value: ";
    std::cin >> val;

    return val;
}

// Request char operator from user
char getUserOperator()
{

    char op{};
    std::cout << "Enter one of the following: +, -, *, or /: ";
    std::cin >> op;

    return op;
}

// Calculator Function
double calculator(double val1, double val2, char opr)
{
    double calc{};

    if (opr == '+') // addition
        calc = (val1 + val2);
    else if (opr == '-') // subtraction
        calc = (val1 - val2);
    else if (opr == '*') // multiplication
        calc = (val1 * val2);
    else if (opr == '/') // division
        calc = (val1 / val2);

    return calc;
}
