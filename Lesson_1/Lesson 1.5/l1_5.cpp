#include <iostream>

int main(){

    std::cout << "Type a number\n";

    int x {};   //x will store the value of the user

    std::cin >> x;

    std::cout << "User typed the value " << x << "." << std::endl;

    return 0;
}