/*
 Quizz 3:
     What’s wrong with the following code? Update the program to be best
 practices compliant.
*/

/*
    Things I found to be wrong:
    1- creating shared_ptr resource explicitly instead of std::make_shared,
   opening error in 2: 2- shared pointers to same object should be created from
   the first shr_ptr and not to the object, as this means the shared_pointers
   are not tied together, and will both attempt to destruct the dynamic object,
   leading to undefined behavior as the last shrd_pointer to be destroyed tries
   to destroy an already destroyed object.

    Fix: use make_shared to create ptr1 and ptr2 from res object
*/

#include <iostream>
#include <memory>  // for std::shared_ptr

class Resource {
   public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};

int main() {
    auto ptr1{std::make_shared<Resource>()};
    auto ptr2{ptr1};

    return 0;
}