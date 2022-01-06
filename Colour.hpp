#pragma once
#include "Vector.hpp"
#include <iostream>

class Colour {
  double r, g, b;

public:
  Colour(double r, double g, double b);
  double getR() const;
  double getG() const;
  double getB() const;

  Colour &operator+=(const Colour &colour);

  // do merge function later
};

void printColour(std::ostream &out, const Colour &colour, int samples);

inline Colour operator+(const Colour &c1, const Colour &c2) {
  return Colour(c1.getR() + c2.getR(), c1.getG() + c2.getG(),
                c1.getB() + c2.getB());
}
inline Colour operator+(const Vector &v1, const Colour &c2) {
  return Colour(v1.getX() + c2.getR(), v1.getY() + c2.getG(),
                v1.getZ() + c2.getB());
}
inline Colour operator-(const Colour &c1, const Colour &c2) {
  return Colour(c1.getR() - c2.getR(), c1.getG() - c2.getG(),
                c1.getB() - c2.getB());
}
inline Colour operator*(const Colour &c1, const Colour &c2) {
  return Colour(c1.getR() * c2.getR(), c1.getG() * c2.getG(),
                c1.getB() * c2.getB());
}
inline Colour operator*(double t, const Colour &c1) {
  return Colour(c1.getR() * t, c1.getG() * t, c1.getB() * t);
}
inline Colour operator*(const Colour &c1, double t) {
  return Colour(c1.getR() * t, c1.getG() * t, c1.getB() * t);
}
inline Colour operator/(const Colour &c1, double t) { return (1 / t) * c1; }
inline double dotProduct(const Colour &c1, const Colour &c2) {
  return c1.getR() * c2.getR() + c1.getG() * c2.getG() + c1.getB() * c2.getB();
}
