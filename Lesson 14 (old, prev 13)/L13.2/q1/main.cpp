/*
 Quizz 1:
 a) Create a class called IntPair that holds two integers.
 This class should have two member variables to hold the integers.
 You should also create two member functions:
    one named “set” that will let you assign values to the integers,
    and one named “print” that will print the values of the variables.

 The following main function should execute and produce the output:
 Pair(1, 1)
 Pair(2, 2)
*/

#include <iostream>
#include <limits>   // for numeric_limits
#include <functional> // for std::function
#include <cassert>

class IntPair
{
public:
    int m_a{};
    int m_b{};
    // Method to assign values to the integers
    void set(int x, int y)
    {
        m_a = x;
        m_b = y;
    };
    // Method to print values of pair
    void print()
    {
        std::cout << "Pair(" << m_a << ", " << m_b << ')' << std::endl;
    };
};

int main()
{
    IntPair p1;
    p1.set(1, 1); // set p1 values to (1, 1)

    IntPair p2{2, 2}; // initialize p2 values to (2, 2)

    p1.print();
    p2.print();

    return 0;
}