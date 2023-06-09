#ifndef VECTOR3D_HPP    // Header guard
#define VECTOR3D_HPP

#include "Point3d.h" // for declaring Point3d::moveByVector() as a friend

class Vector3d
{
private:
	double m_x{};
	double m_y{};
	double m_z{};

public:
	Vector3d(double x = 0.0, double y = 0.0, double z = 0.0);

	void print() const;
	
	// Make Point3d a friend class of Vector3d
	friend void Point3d::moveByVector(const Vector3d& v);
};


#endif