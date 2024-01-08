/*Write a program that asks the user to enter a number, and then enter a second number. 
The program should tell the user what the result of adding and subtracting the two numbers is. */

#include <iostream>

int main(){

    //Variables for the two user values
    int a{}, b{};

    //Request first user value
    std::cout   << "Enter an integer: ";
    std::cin    >> a;

    //Request first user value
    std::cout   << "\nEnter another integer: ";
    std::cin    >> b;

    //Calculate sum bettwen the two user values and present them back
    std::cout   << "\n" << a << " + " << b << " is " << a+b << ".\n";

    //Calculate difference bettwen the two user values and present them back
    std::cout   << a << " - " << b << " is " << a-b << ".\n";

    return 0;
}