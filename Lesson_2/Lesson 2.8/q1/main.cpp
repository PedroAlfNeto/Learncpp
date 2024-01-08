
#include <iostream>

//function: Request integer to user
int getInteger();


int main(){

    //Request two integers from user to sum
    int x {getInteger()};
    int y {getInteger()};    

    std::cout << x << "+" << y << " = " << x+y << "\n";

    return 0;
}