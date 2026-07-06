/*
 Quizz 1:
 Fix the program presented in the section “A reductive case” so that the
 Resource is properly deallocated. Do not alter the code in main().
*/

#include <iostream>
#include <memory>  // for std::shared_ptr

class Resource {
   public:
    std::weak_ptr<
        Resource>  // <<< must be weak_ptr instead of shared_ptr to not create
        m_ptr{};  // circular dependency and block the shared pointer from being
                  // destroid after going out of scope at the end of main

    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main() {
    auto ptr1{std::make_shared<Resource>()};

    ptr1->m_ptr = ptr1;  // m_ptr is now sharing the Resource that contains it

    return 0;
}