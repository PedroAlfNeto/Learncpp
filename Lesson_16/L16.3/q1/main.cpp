/*
 Quizz 1:
 Initialize a std::vector with the following values: 'h', 'e', 'l', 'l', 'o'.
 Then print the length of the array (use std::size()).
 Finally, print the value of the element with index 1 using the subscript
 operator and the at() member function. The program should output the following:
    The array has 5 elements.
    ee

 b) What type does size_type default to? Is it signed or unsigned?
 Unsigned int resulting from sizeof

 c) Which functions to get the length of a container return size_type?
 sizeof and std::size() (-std=c++20)
*/

#include <iostream>
#include <vector>


int main() {
    std::vector<char> my_string{'h', 'e', 'l', 'l', 'o'};
    constexpr std::size_t index{1};

    std::cout << "The array has " << std::size(my_string) << " elements.\n"; // std::size requires -std=c++20
    std::cout << my_string[index] << my_string.at(index); 

    return 0;
}