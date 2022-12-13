#include <iostream>

int main()
{
    const int x{2};
    //int y{};
    const int& refx{x};

    const int* const ptrx {&x};

    std::cout << "x =\t" << x << "\nrefx =\t" << refx << "\n&x =\t" << &x << "\n&refx =\t?\n";
    
    // ptrx++; // test as not compilable

    std::cout << "*ptrx =\t" << *ptrx << "ptrx =\t"<< ptrx <<"\n";

    return 0;
}