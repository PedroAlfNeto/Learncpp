/*
 Quizz 1:
 Write function prototypes for the following cases. Use const if/when necessary:
    a) A function named max() that takes two doubles and returns the larger of the two.
    b) A function named swap() that swaps two integers.
    c) A function named getLargestElement() that takes a dynamically allocated array of integers 
        and returns the largest number in such a way that the caller can change the value of the 
        element returned (don’t forget the length parameter).
*/

#include <iostream>

// a) function takes two doubles and returns larger of two
double max(double x,double y);

// b) function swaps two integers
void swap(int& x, int& y);

// c) function takes a dynamically allocated array of integers and returns address of largest number
int& getLargestElement(int* array, const int arSize);

int main(){
    /*
    // a) function takes two doubles and returns larger of two
    auto max{
        [=](const double a,const double b){
            if(a>b)
                return a;
            else return b;
        }
    };

    //  b) A function named swap() that swaps two integers.
    auto swap{
        [&](int a, int b){
            int tmp{};
            tmp=a;
            b=a;
            a=tmp;
        }
    };


    std::cout << "Largest between 3.14 and 5.18 is: " << max(3.14,5.18) << '\n'; 
    // std::cout << "x = 13, y=2\nSwitching x and y results in x=" << max(3.14,5.18) << '\n'; 
*/ //only prototypes
    return 0;
}