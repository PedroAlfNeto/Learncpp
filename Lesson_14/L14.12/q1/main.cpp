/*
 Quizz 1:
 Write a class named Ball. Ball should have two private member variables,
 one to hold a color (default value: black), and one to hold a radius (default
 value: 10.0).

 Add 4 constructors, one to handle each case below:
*/

#include <iostream>
#include <string>
#include <string_view>

class Ball {
 public:
  // Default constructure
  Ball(){
    print();
  }

  // Constructor to set only m_color
  Ball(std::string_view c) : m_color{c} {
    print();
  }

  // Constructor to set only m_radius
  Ball(double r): m_radius {r} {
    print();
  }

  // Constructor to set m_color and m_radius
  Ball(std::string_view c, double r) : m_color{c}, m_radius(r) {
    print();
  }

  // Class print function
  void print(){
        std::cout << "Ball (" << m_color << ", " << m_radius << ")\n";
    }

 private:
  std::string m_color{"black"};
  double m_radius{10.0};
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}