/*
 Quizz 1:
 A prime number is a natural number greater than 1 that is evenly divisible (with no remainder) only
 by 1 and itself. Complete the following program by writing the isPrime() function using a for-loop.
 When successful, the program will print “Success!”.
*/

#include <iostream>
#include <cassert>

bool isPrime(int x) // q2: write this function using a for loop
{
    // 0 and 1 are non prime numbers that cannot be validated by integer division
    if ((x == 1) || (x == 0)){
        return false;
    }

    // Loop bettween and excluding: 1 to x
    for (int i = 2; i < x; ++i) // prime density density decreases with
    {
        // Remainder of the integer division must allways differ 0 in prime number
        if ((x % i) == 0){
            return false;
        }
    }

    // Reached only if x is prime
    return true;
}

int main()
{
    // assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";

    return 0;
}