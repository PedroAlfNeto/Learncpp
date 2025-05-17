/*
 Quizz 2:
 What’s wrong with these programs?
*/

// a)
int& doSomething()
{
    int array[]{ 1, 2, 3, 4, 5 };
    return array[3];
}
// A: Dangling referrence returned. array goes out of scope and we return the address to it. 
// Undefined behaviour




//b)
int sumTo(int value)
{
    return value + sumTo(value - 1);
}
// A: Infinite recursion. Missing termination condition. Stack overflows


// c)
float divide(float x, float y)
{
    return x / y;
}

double divide(float x, float y)
{
    return x / y;
}
// A: Function overloading cannot be resolved based on return type. Will not compile.
// Missed: Also allows division by 0.



// d)
#include <iostream>

int main()
{
    int array[100000000]{};

    for (auto x: array)
        std::cout << x << ' ';

    std::cout << '\n';

    return 0;
}
// A: Array size is too large, using up the stack. Should use dynamic allocation 
// with std::vector



// e)
#include <iostream>

int main(int argc, char* argv[])
{
    int age{ argv[1] };
    std::cout << "The user's age is " << age << '\n';

    return 0;
}
// A: Accessing argv[1] that may not be provided to the program. Undefined behaviour
// accessing potentially unninitialized address.