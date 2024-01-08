/*
 Question 1: old 13 (not included in new 14)
 c) Change function distanceTo from a member function to a non-member friend
 function that takes two Points as parameters. Also rename it “distanceFrom”.

 The following main should run and print:
 > Point2d(0, 0)
 > Point2d(3, 4)
 > Distance between two points: 5
*/

#include <iostream>
#include <cmath>



class Point2d
{
private:
    const double m_x;
    const double m_y;

public:
    // default constructor
    Point2d()
        : m_x{0.0}, m_y{0.0}
    {
    }

    // constructor with two inputs
    Point2d(double x, double y)
        : m_x{x}, m_y{y}
    {
    }

    // Print coordinates of 2d point
    void print()
    {
        std::cout << "Point2d(" << this->m_x << "," << this->m_y << ")\n";
    }

    friend double distanceFrom(const Point2d &a, const Point2d &b);
};

// Caculate distance between two 2d points
double distanceFrom(const Point2d &a, const Point2d &b)
{
    return (std::sqrt((a.m_x - b.m_x) * (a.m_x - b.m_x) + (a.m_y - b.m_y) * (a.m_y - b.m_y)));
}

int main()
{
    Point2d first{};
    Point2d second{3.0, 4.0};
    first.print();
    second.print();
    std::cout << "Distance between two points: " << distanceFrom(first, second) << '\n';

    return 0;
}