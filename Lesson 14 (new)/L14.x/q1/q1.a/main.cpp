/*
 Question 1:
 a) Write a class named Point2d. Point2d should contain two member variables of type double: 
    m_x, and m_y, both defaulted to 0.0. Provide a constructor and a print function.

 The following main should run and print:
 > Point2d(0, 0)
 > Point2d(3, 4)
*/

#include <iostream>

class Point2d
{
private:
    double m_x{};
    double m_y{};

public:
    // default constructor
    Point2d() = default;

    // constructor with two inputs
    Point2d(double x, double y)
        : m_x{x}, m_y{y}
    {
    }

    // Print coordinates of 2d point
    void print()
    {
        std::cout << "Point2d("<< this->m_x << "," << this->m_y <<")\n";
    }
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented
    
    first.print();
    second.print();

    return 0;
}