#pragma once
#include <iostream>

class Vector {
  double x, y, z;

public:
  Vector();
  Vector(double x, double y, double z);
  double getX();
  double getY();
  double getZ();
  Vector crossProduct(Vector vect);
  Vector normalize();

  friend std::ostream &operator<<(std::ostream &os, const Vector &p) {
    return os << p.x << ", " << p.y << ", " << p.z;
  }
};

Vector operator+(Vector v1, Vector v2);
Vector operator*(Vector v, double num);
