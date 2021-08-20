#pragma once
#include "Object.hpp"
#include "Point.hpp"
#include "Ray.hpp"

class Sphere : public Object {
  Point pos;
  double r;

public:
  Sphere(Point pos, double r);
  Point getPos() { return pos; }
  double getR() { return r; }
  std::pair<double, double> modified_quadratic_formula(double a, double b,
                                                       double c);
  double getIntersectionDistance(Ray ray);
  // pass a ray to this sphere -> return
};
