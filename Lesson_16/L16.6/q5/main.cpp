/*
 Quizz 5:
 Write a function template to find the largest value in a std::vector. 
 If the vector is empty, return the default value for the element type.

 The following code should execute: (main)

 And print the following result:
    92
    -13
    0
*/

#include <iostream>
#include <vector>

template<typename T>
T findMax(std::vector<T>& vec){
    T max{}; //default value for the element type

    if(vec.size()>0) max=vec.at(0); // set max with first element

    for(std::size_t idx{0}; idx < vec.size(); ++idx){
        // update new found maximum
        if(vec.at(idx)>max) max=vec.at(idx);
    }

    return max;
}

int main()
{
    std::vector data1 { 84, 92, 76, 81, 56 };
    std::cout << findMax(data1) << '\n';

    std::vector data2 { -13.0, -26.7, -105.5, -14.8 };
    std::cout << findMax(data2) << '\n';

    std::vector<int> data3 { };
    std::cout << findMax(data3) << '\n';

    return 0;
}