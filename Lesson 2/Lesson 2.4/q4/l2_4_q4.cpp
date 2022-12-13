#include <iostream>

//Function calculates double the input value
int doubleNumber(int a){
    
    return a*2; 
} 

int main(){

    std::cout << "Double of 3 is: " << doubleNumber(3) << std::endl;

    return 0;
}