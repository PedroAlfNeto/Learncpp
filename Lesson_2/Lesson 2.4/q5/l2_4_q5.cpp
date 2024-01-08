#include <iostream>


//Function calculates double the input value
int doubleNumber(int a){

    return a*2; 
} 

//
int getValueFromUser(){

    //Request integer to user
    std::cout << "Enter an integer: ";

    //Store integer value in variable
    int x{};
    std::cin >> x;

    return x;
}


int main(){

    int val{};
    val = getValueFromUser();

    std::cout << "Double of " << val << " is: " << doubleNumber(val) << std::endl;

    return 0;
}