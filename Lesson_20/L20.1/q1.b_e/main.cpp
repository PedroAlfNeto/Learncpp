/*
 Quizz 1:

 1 - In this quiz, we’re going to write a version of our basic calculator using
 function pointers.

 1b) Write functions named add(), subtract(), multiply(), and divide().
 These should take two integer parameters and return an integer.

 1c) Create a type alias named ArithmeticFunction for a pointer to a function
 that takes two integer parameters and returns an integer.
 // Use std::function, and include the appropriate header.

 1d) Write a function named getArithmeticFunction() that takes an operator
 character and returns the appropriate function as a function pointer.

 1e) Modify your main() function to call getArithmeticFunction(). 
 Call the return value from that function with your inputs and print the result.
*/

#include <iostream>

int add(int x, int y) { return x + y; }

int subtract(int x, int y) { return x - y; }

int multiply(int x, int y) { return x * y; }

int divide(int x, int y) { return x / y; }

using ArithmeticFunction = int (*)(int, int);

// Alternative using std::func 
// #include <functional
// using ArithmeticFunction = std::function<int(int, int)>;

ArithmeticFunction getArithmeticFunction(char oper) {
    switch (oper) {
        case '+':
            return add;
        case '-':
            return subtract;
        case '*':
            return multiply;
        case '/':
            return divide;
        default:
            std::cout << "Error Invalid operator inserted!\n";
            return nullptr;
    }
}

void calculator(int n1, int n2, char oper) {
    int res{};

    ArithmeticFunction opfunc{getArithmeticFunction(oper)};

    if (opfunc) {  // check if valid operation
        res = opfunc(n1, n2);
    } else {
        std::cout << "Error Invalid operator inserted!\n";
        return;
    }

    // Print results
    std::cout << '\n' << n1 << oper << n2 << " = " << res << '\n';

    return;
}

int getInteger() {
    std::cout << "\nEnter an integer: ";
    int val{};
    std::cin >> val;

    return val;
}

char getoper() {
    char op{};

    do {
        std::cout
            << "\nEnter one of the following operators: +, -, *, or /: ";
        std::cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    return op;
}

int main() {
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
