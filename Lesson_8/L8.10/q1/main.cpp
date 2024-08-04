/*
 Quizz 1:
 Write a for-loop that prints every even number from 0 to 20.
*/

#include <iostream>


int main(){

    for(int idx{0}; idx<20+1; idx+=2){
        std::cout << idx <<'\n';
    }

    return 0;
}
