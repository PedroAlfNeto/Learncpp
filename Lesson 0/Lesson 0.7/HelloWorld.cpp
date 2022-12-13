#include <stdio.h>
#include <iostream>

int main()
{
    printf("Hello world\n");
    
    std::cout << "Hello world\n"
              << std::endl;

    printf("Press a key to continue...\n");

    // get one more char from the user (waits for user to press enter)
    std::cin.get();

    return 0;
}