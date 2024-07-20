/*
 Quizz 1:
 Question #1

    Write a function that takes two parameters: a std::vector and an index. 
    If the index is out of bounds, print an error. 
    If the index is in bounds, print the value of the element.

    The following sample main should compile:
*/

#include <iostream>
#include <vector>

// Write your printElement function here
template<typename T>
void printElement(std::vector<T> &vec, int index){

    // check if index is out of bounds
    if(std::size(vec)<=index){
        std::cout << "Invalid index" << '\n';
    }
    else{
        std::cout << "The element has value " << vec.at(index) << '\n';
    }

    return;
}


int main()
{
    // requires c++17 or furhter, otherwise std:vector<type> cant be done with CTAD
    std::vector v1 { 0, 1, 2, 3, 4 }; 
    printElement(v1, 2);
    printElement(v1, 5);

    std::vector v2 { 1.1, 2.2, 3.3 };
    printElement(v2, 0);
    printElement(v2, -1);

    return 0;
}