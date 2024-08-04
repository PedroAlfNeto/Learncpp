/*
 Quizz 1:
 Write a short program that prints the elements of the following vector to the 
  screen using a loop:

  The output should look like this:
    4 6 7 3 8 2 1 9
    
 Quizz 2:
 Update your code for the prior quiz solution so that the following program compiles and has the same output:
*/

#include <iostream>
#include <vector>

// Q1
// void printArray(std::vector<int>& vec){
//     for(std::size_t idx{0}; idx < std::size(vec); ++idx){
//         std::cout << vec.at(idx) << ' ';
//     }
// }

// Q2v1 : // use function template to print array
// template<typename T>
// void printArray(std::vector<T>& vec){
//     for(std::size_t idx{0}; idx < vec.size(); ++idx){
//         std::cout << vec.at(idx) << ' ';
//     }

//     if (vec.size() > 0)
//         std::cout << '\n';
// }

// Q2v2 (requires c++20 for abbreviation function templates)
void printArray(auto &vec){
    for(std::size_t idx{0}; idx < vec.size(); ++idx){
        std::cout << vec.at(idx) << ' ';
    }

    if (vec.size() > 0)
        std::cout << '\n';
}


int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    printArray(arr);

    return 0;
}