/*
 Quizz 3:
 Let’s write a class that implements a simple stack from scratch.
 The class should be named Stack, and should contain:
    A private array of integers of length 10.
    A private integer to keep track of the size of the stack.
    A public member function named reset() that sets the size to 0.
    A public member function named push() that pushes a value on the stack.
        push() should return false if the array is already full, and true otherwise.
    A public member function named pop() that pops a value off the stack and returns it.
        If there are no values on the stack, the code should exit via an assert.
    A public member function named print() that prints all the values in the stack.
*/

#include <iostream>
#include <array>
#include <cassert>

// Write a class named Point3d:
class Stack
{
private:
    // A private array of integers of length 10.
    std::array<int, 10> m_array{};
    // A private integer to keep track of the size of the stack.
    int m_index{};

public:
    // A public member function named reset() that sets the size to 0.
    void reset()
    {
        m_index = 0;
    }
    // A public member function named push() that pushes a value on the stack.
    bool push(int x)
    {
        if (m_index < 9)
        {
            m_array[m_index] = x; // overwrite any existing
            ++m_index;            // increase stack pointer
            return true;          // pushed value
        }
        
        //  push() should return false if the array is already full, and true otherwise.
        return false; // Stack already full
    }
    // A public member function named pop() that pops a value off the stack and returns it.
    void pop()
    {
        // If there are no values on the stack, the code should exit via an assert.
        assert((m_index > 0) && "There are no values on the stack"); // program will terminate
        --m_index;
    }
    // A public member function named print() that prints all the values in the stack.
    void print()
    {
        std::cout << "( ";
        for (int idx{0}; idx < m_index ; idx ++)
        {
            std::cout << m_array[idx] << ' ';
        }
        std::cout << ")\n";
    }
};

int main()
{
    Stack stack;
    stack.print();

    stack.push(5);
    stack.push(3);
    stack.push(8);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.print();

    return 0;
}