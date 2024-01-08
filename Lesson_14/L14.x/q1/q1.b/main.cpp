/*
 Question 1:
 b) Now add a member function named distanceTo that takes another Point2d as a parameter,
    and calculates the distance between them.
 Given two points (x1, y1) and (x2, y2), the distance between them can be calculated as
    std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)).
 The std::sqrt function lives in header cmath.

 The following main should run and print:
 > Point2d(0, 0)
 > Point2d(3, 4)
 > Distance between two points: 5
*/

#include <cmath>
#include <iostream>

class Point2d {
 private:
  double m_x{};
  double m_y{};

 public:
  // default constructor
  Point2d() = default;

  // constructor with two inputs
  Point2d(double x, double y) : m_x{x}, m_y{y} {}

  // Print coordinates of 2d point
  void print() {
    std::cout << "Point2d(" << this->m_x << "," << this->m_y << ")\n";
  }

  // Caculate distance between two 2d points
  double distanceTo(const Point2d &sec) {
    return (std::sqrt((m_x - sec.m_x) * (m_x - sec.m_x) +
                      (m_y - sec.m_y) * (m_y - sec.m_y)));
  }
};

int main() {
  Point2d first{};
  Point2d second{3.0, 4.0};
  
  first.print();
  second.print();

  std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

  return 0;
}