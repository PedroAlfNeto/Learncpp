/*
 Quizz 1:
 Define a std::vector using CTAD and initialize it with the first 5 positive square numbers (1, 4, 9, 16, and 25).
 
 Q2
 What’s the behavioral difference between these two definitions? 1 list initializer = v1{5}, 2nd constructore initalized = v1{0,0,0,0,0}
*/

#include <vector>

std::vector my_vec{1, 4, 9, 16, 25};