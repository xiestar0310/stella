#pragma once
#include <iostream>

class Vector {
  double x, y, z;

public:
  Vector();
  Vector(double x, double y, double z);
  double getX() const;
  double getY() const;
  double getZ() const;
  double length() const;
  Vector normalize() const;

  Vector &operator+=(const Vector &vect);
  Vector &operator*=(const double t);
  Vector &operator/=(const double t);
  Vector operator-() const { return Vector(-x, -y, -z); }

  friend std::ostream &operator<<(std::ostream &os, const Vector &p) {
    return os << p.x << ", " << p.y << ", " << p.z;
  }
};

inline Vector operator+(const Vector &v1, const Vector &v2) {
  return Vector(v1.getX() + v2.getX(), v1.getY() + v2.getY(),
                v1.getZ() + v2.getZ());
}
inline Vector operator-(const Vector &v1, const Vector &v2) {
  return Vector(v1.getX() - v2.getX(), v1.getY() - v2.getY(),
                v1.getZ() - v2.getZ());
}
inline Vector operator*(const Vector &v1, const Vector &v2) {
  return Vector(v1.getX() * v2.getX(), v1.getY() * v2.getY(),
                v1.getZ() * v2.getZ());
}
inline Vector operator*(double t, const Vector &v1) {
  return Vector(v1.getX() * t, v1.getY() * t, v1.getZ() * t);
}
inline Vector operator*(const Vector &v1, double t) {
  return Vector(v1.getX() * t, v1.getY() * t, v1.getZ() * t);
}
inline Vector operator/(const Vector &v1, double t) { return (1 / t) * v1; }
inline double dotProduct(const Vector &v1, const Vector &v2) {
  return v1.getX() * v2.getX() + v1.getY() * v2.getY() + v1.getZ() * v2.getZ();
}
inline Vector crossProduct(const Vector &v1, const Vector &v2) {
  return Vector(v1.getY() * v2.getZ() - v1.getZ() * v2.getY(),
                v1.getZ() * v2.getX() - v1.getX() * v2.getZ(),
                v1.getX() * v2.getY() - v1.getY() * v2.getX());
}
