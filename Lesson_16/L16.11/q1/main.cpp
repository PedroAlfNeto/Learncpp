/*
 Quizz 1:
 Write a program that pushes and pops values, and outputs the following
 sequence:

    (Stack: empty)
    Push 1 (Stack: 1)
    Push 2 (Stack: 1 2)
    Push 3 (Stack: 1 2 3)
    Pop    (Stack: 1 2)
    Push 4 (Stack: 1 2 4)
    Pop    (Stack: 1 2)
    Pop    (Stack: 1)
    Pop    (Stack: empty)
*/

#include <iostream>
#include <vector>

class Stack {
   private:
    std::vector<int> m_stack{};  // empty stack

    void printStack() {
        std::cout << "\t(Stack: ";

        if (m_stack.empty()) {
            std::cout << "empty";
        } else {
            for (const auto element : m_stack) {
                std::cout << element << ' ';
            }
        }
        std::cout << ")\n";
    }

   public:
    // constructor - always empty stack
    Stack() { printStack(); };

    void push(int val) {
        std::cout << "Push " << val << ' ';
        m_stack.push_back(val);
        printStack();
    }

    void pop() {
        std::cout << "Pop ";
        m_stack.pop_back();
        printStack();
    }
};

int main() {
    Stack stack{};  // empty stack

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.push(4);
    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}