#include "input.hpp"

#include <iostream>

int getInteger(){

    //Get an integer value from user
    std::cout   << "Enter an integer: ";
    int x{};
    std::cin    >> x;
    
    return x;
}