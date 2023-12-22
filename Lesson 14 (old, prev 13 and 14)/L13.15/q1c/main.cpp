/*
 Quizz 1:
 1. In geometry, a point is a position in space. 
 We can define a point in 3d-space as the set of coordinates x, y, and z. 
 For example, the Point(2.0, 1.0, 0.0) would be the point at coordinate space 
 	x=2.0, y=1.0, and z=0.0.
In physics, a vector is a quantity that has a magnitude (length) and a direction (but no position). 
We can define a vector in 3d-space as an x, y, and z value representing the direction of the vector 
	along the x, y, and z axis (the length can be derived from these). 
For example, the Vector(2.0, 0.0, 0.0) would be a vector representing a direction along the positive 
	x-axis (only), with length 2.0.

	1c) Reimplement the solution to quiz question 1b using 5 separate files: 
		Point3d.h, Point3d.cpp, Vector3d.h, Vector3d.cpp, and main.cpp.

Thanks to reader Shiva for the suggestion and solution.
*/

#include "Vector3d.hpp"
#include "Point3d.hpp"


int main()
{
	Point3d p{1.0, 2.0, 3.0};
	Vector3d v{2.0, 2.0, -3.0};

	p.print();
	p.moveByVector(v);
	p.print();

	return 0;
}