#include <iostream>
#include <string>

int main()
{
    std::string array[]{ "peter", "likes", "frozen", "yogurt"};
    for (auto& element: array) // element is a const reference to the currently iterated array element
    {
        element[0]='l';
        std::cout << element << ' ';
    }

    std::cout << '\n';

    for (auto element: array) // element is a const reference to the currently iterated array element
    {
        std::cout << element << ' ';
    }
    std::cout << "\nString max size: "<< array[3]; 
    return 0;
}