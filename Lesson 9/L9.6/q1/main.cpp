/*
 Quizz 1:
 What’s wrong with this snippet of code?
*/

//#include "main.hpp"
#include <iostream>

int main()
{
    int value{ 45 };
    int* ptr{ &value }; // declare a pointer and initialize with address of value
    //*ptr = &value; // assign address of value to ptr

    return 0;
}