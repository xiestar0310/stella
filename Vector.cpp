#include "Vector.hpp"
#include <cmath>

Vector::Vector() {
  x = 0;
  y = 0;
  z = 0;
}

Vector::Vector(double x, double y, double z) {
  this->x = x;
  this->y = y;
  this->z = z;
}
double Vector::getX() { return x; }
double Vector::getY() { return y; }
double Vector::getZ() { return z; }

Vector Vector::crossProduct(Vector vect) {
  return Vector(y * vect.z - z * vect.y, z * vect.x - x * vect.z,
                x * vect.y - y * vect.x);
}

Vector Vector::normalize() {
  double length = std::sqrt(x * x + y * y + z * z);
  return Vector(x / length, y / length, z / length);
}

Vector operator+(Vector v1, Vector v2) {
  return Vector(v1.getX() + v2.getX(), v1.getY() + v2.getY(),
                v1.getZ() + v2.getZ());
}

Vector operator*(Vector v, double num) {
  return Vector(v.getX() * num, v.getY() * num, v.getZ() * num);
}

double operator*(Vector v1, Vector v2) {
  return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}
