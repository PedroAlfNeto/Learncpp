/*
 Quizz 1:
 In this quiz, we’re going to write a version of our basic calculator using function pointers.

 1a) Create a short program asking the user for two integer inputs and a mathematical operation:
    (‘+’, ‘-‘, ‘*’, ‘/’).
 Ensure the user enters a valid operation.

 1b) Write functions named add(), subtract(), multiply(), and divide().
 These should take two integer parameters and return an integer.

 1c) Create a type alias named ArithmeticFunction for a pointer to a function that takes
 two integer parameters and returns an integer.
 Use std::function, and include the appropriate header.

 1d) Write a function named getArithmeticFunction() that takes an operator character and
 returns the appropriate function as a function pointer.

 1e) Modify your main() function to call getArithmeticFunction().
 Call the return value from that function with your inputs and print the result.
*/

#include <iostream>
#include <limits>   // for numeric_limits
#include <functional> // for std::function
#include <cassert>

constexpr std::streamsize streamMax{std::numeric_limits<std::streamsize>::max()};

using ArithmeticFunction = std::function<int(int, int)>;

// Declarations
bool validateCinInput();
bool validateOperator(char oper);
int getInteger();
char getOperator();

int add(int a, int b)
{
    return a + b;
}
int subtract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}

ArithmeticFunction getArithmeticFunction(char oper)
{
    switch(oper)
    {
    case '+':
        return &add;
    case '-':
        return &subtract;
    case '*':
        return &multiply;
    case '/':
        return &divide;
    default:
        assert(false && "Invalid operator after validation");
        return nullptr;
    }
}

int main()
{
    // First integer
    int x{getInteger()};
    // Operator
    char op{getOperator()};
    // Second integer
    int y{getInteger()};

    ArithmeticFunction ptrArithmeticFunc{getArithmeticFunction(op)};

    std::cout << '\n' << x << op << y << '=' <<ptrArithmeticFunc(x,y);

    // x++;y++;op++; //TEST: bypass -Werror

    return 0;
}


bool validateCinInput()
{
    // In case of invalid input
    if(std::cin.fail())
    {
        // Clear cin error flag
        std::cin.clear();

        // Ignore cin input    
        std::cin.ignore(streamMax, '\n');

        // Invalid input
        return true;
    }

    // Valid input
    return false;
}

bool validateOperator(char oper)
{
    switch(oper)
    {
    case '+':
    case '-':
    case '*':
    case '/': //Intentional fallthrough
        return false;
    default:
        std::cout << "Invalid input!\n";
        return true;
    }
}

int getInteger()
{
    int value{};
    std::cout << "Intert integer: ";
    std::cin >> value;

    // Retry until valid input
    while(validateCinInput())
    {

        std::cout << "Invalid input!\nIntert integer: ";
        std::cin >> value;
    }

    return value;
}

char getOperator()
{
    char oper{};

    // Retry until valid input operator
    do
    {
        std::cout << "Intert operator (+, -, * or /): ";
        std::cin >> oper;

        // Validate input as char
        while(validateCinInput())
        {
            std::cout << "Invalid input!\n";
            std::cin >> oper;
        }
        // Validate operator
    } while(validateOperator(oper));

    return oper;
}