#include "Vector.hpp"
#include <cmath>

Vector::Vector() : x(0), y(0), z(0) {}
Vector::Vector(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector::getX() const { return x; }
double Vector::getY() const { return y; }
double Vector::getZ() const { return z; }

double Vector::length() const { return std::sqrt(x * x + y * y + z * z); }

double Vector::lengthSquared() const { return x * x + y * y + z * z; }

Vector Vector::normalize() const {
  double length = this->length();
  return Vector(x / length, y / length, z / length);
}

Vector &Vector::operator+=(const Vector &vect) {
  x += vect.x;
  y += vect.y;
  z += vect.z;
  return *this;
}

Vector &Vector::operator*=(const double t) {
  x *= t;
  y *= t;
  z *= t;
  return *this;
}

Vector &Vector::operator/=(const double t) { return *this *= 1 / t; }

Vector randomInUnitSphere() {
  while (true) {
    Vector p = Vector::random(-1, 1);
    if (p.lengthSquared() >= 1)
      continue;
    return p;
  }
}
