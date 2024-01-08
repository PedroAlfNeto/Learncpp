/*
 Quizz 2:
 Reduce the number of constructors in the from L14.12.q2 program by using
 default arguments and delegating constructors.
*/

#include <iostream>
#include <string>
#include <string_view>

class Ball {
 public:
  // Constructor to set only m_color (also default constructor)
  Ball(std::string c = "black",
       double r = 10.0)  // cannot use std::string_view here
      : m_color{c}, m_radius{r} {
    print();
  }

  // Constructor to set only m_radius
  Ball(double r) : m_radius{r} { print(); }

  // Class print function
  void print() {
    std::cout << "Ball (" << m_color << ", " << m_radius << ")\n";
  }

 private:
  std::string m_color{"black"};
  double m_radius{10.0};
};

int main() {
  Ball def{};
  Ball blue{"blue"};
  Ball twenty{20.0};
  Ball blueTwenty{"blue", 20.0};

  return 0;
}