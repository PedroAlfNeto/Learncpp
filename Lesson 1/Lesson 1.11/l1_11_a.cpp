// In this programm i'll attempt to do the program before the lesson
#include <iostream>

int main(){

    int x{}; //variable to store user's input integer

    //Request integer to user
    std::cout << "Enter an integer: ";

    //Store integer value in variable
    std::cin >> x;

    //Double the user's value and print it back in the console
    std::cout << "\nDouble that number is: " << x*2 << std::endl;

    return 0;
}
