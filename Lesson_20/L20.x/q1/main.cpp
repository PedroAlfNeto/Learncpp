/*
 Quizz 1:
 Write function prototypes for the following cases. Use const if/when necessary.
*/

#include

// a) A function named max() that takes two doubles and returns the larger of
// the two.
double max(double a,
           double b);  // const is useless here as only confuses the reader
// Constness of pass-by-value parameters at declaration and definition are
// allowed to differ

// b) A function named swap() that swaps two integers.
int swap(int& a, int& b);

// c) A function named getLargestElement() that takes a dynamically allocated
// array of integers and returns the largest number in such a way that the
// caller can change the value of the element returned (don’t forget the length
// parameter).

int& getLargestElement(int* arr, int len);
// Note: array can't be const in this case, because returning a non-const
// reference to a const element would be a const violation.