#include "io.hpp"
#include <iostream>

int readNumber(void)
{

    int val{};

    std::cout << "Enter an integer value\n";
    std::cin >> val;

    return val;
}

void writeAwnser(int res)
{
    // std::cout << x << "+" << y << " = " << x+y << "\n";
    std::cout << "Sum of the values is " << res << "\n";
}