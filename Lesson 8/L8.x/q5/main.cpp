/*
 Quizz 5:
 5a) Write a function template named add that allows the users to add 2 values of the same type. 

 5b) Write a function template named mult that allows the user to multiply one value of 
    any type (first parameter) and an integer (second parameter). 
    The function should return the same type as the first parameter.

 5c) Write a function template named sub that allows the user to 
    subtract two values of different types.
*/

//#include "main.hpp"
#include <iostream>

#include <iostream>

// write your add function template here
template <typename U>
U add(U a, U b){
    return a+b;
}

// write your mult function template here
template <typename U>
U mult(U a, int b){
    return (a*b);
}

// write your sub function template here
// template <typename V, typename U>
//auto sub(V a, U b) prior to c++20
auto sub(auto a, auto b) 
{
    return (a-b);
}

int main()
{
    // 5a) test
    std::cout << "add() test:" << '\n';
	std::cout << add(2, 3) << '\n';
	std::cout << add(1.2, 3.4) << '\n';

    // 5b) test
    std::cout << "mult() test:" << '\n';
    std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

    // 5c) test
    std::cout << "sub() test:" << '\n';
    std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}