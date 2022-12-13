/*
 Quizz 4:
 Now make the numbers print like this:
         1
       2 1
     3 2 1
   4 3 2 1
 5 4 3 2 1
*/

#include <iostream>

int main()
{
  // outer loops between 1 and 5
  int outer{1};
  while (outer <= 5)
  {
    // For each iterat ion of the outer loop, the code in the body of the loop executes once

    // inner loop for printing spaces
    int spacer{5 - outer};
    while (spacer >= 1)
    {
      std::cout << "  ";
      --spacer;
    }

    // inner loops between 5 and 1
    int inner{outer};
    while (inner >= 1)
    {
      std::cout << inner << ' ';
      --inner;
    }

    // print a newline at the end of each row
    std::cout << '\n';
    ++outer;
  }

  return 0;
}