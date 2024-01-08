#include <iostream>

// Validate if a number between 0 and 9 is prime (2, 3, 5, or 7)
bool isPrime(int val)
{
    if (val == 2)
        return true;
    else if (val == 3)
        return true;
    else if (val == 5)
        return true;
    else if (val == 7)
        return true;
    else
        return false;
}

int main()
{

    // Get user number
    std::cout << "\nEnter an integer between 0 and 9: ";
    int x{};
    std::cin >> x;

    if (isPrime(x))
        std::cout << "Digit is prime.\n";
    else
        std::cout << "Digit is not prime.\n";

    return 0;
}